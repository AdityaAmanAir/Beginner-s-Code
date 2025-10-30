#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define SHM_SIZE 1024
#define MAX_MESSAGES 10
#define MESSAGE_SIZE 100

// Union for semaphore operations
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

// Structure for shared memory
struct shared_memory {
    char messages[MAX_MESSAGES][MESSAGE_SIZE];
    int read_index;
    int write_index;
    int message_count;
};

// P operation (wait)
void P(int sem_id, int sem_num) {
    struct sembuf op = {sem_num, -1, 0};
    semop(sem_id, &op, 1);
}

// V operation (signal)
void V(int sem_id, int sem_num) {
    struct sembuf op = {sem_num, 1, 0};
    semop(sem_id, &op, 1);
}

int create_shared_memory() {
    key_t key = ftok(".", 'S');
    int shm_id = shmget(key, sizeof(struct shared_memory), IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }
    return shm_id;
}

int create_semaphores() {
    key_t key = ftok(".", 'T');
    int sem_id = semget(key, 2, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("semget failed");
        exit(1);
    }

    // Initialize semaphores only if newly created
    if (semctl(sem_id, 0, GETVAL) == -1) {
        union semun arg;
        arg.val = 1;  // Mutex semaphore
        if (semctl(sem_id, 0, SETVAL, arg) == -1) {
            perror("semctl mutex init failed");
            exit(1);
        }

        arg.val = 0;  // Message available semaphore
        if (semctl(sem_id, 1, SETVAL, arg) == -1) {
            perror("semctl message_available init failed");
            exit(1);
        }
    }
    return sem_id;
}

void send_message(int shm_id, int sem_id, const char* message) {
    struct shared_memory *shm = shmat(shm_id, NULL, 0);
    if (shm == (void*)-1) {
        perror("shmat in send failed");
        exit(1);
    }

    P(sem_id, 0);  // Lock mutex

    // Wait if buffer is full
    while (shm->message_count >= MAX_MESSAGES) {
        V(sem_id, 0);  // Release mutex temporarily
        printf("Buffer full. Waiting...\n");
        sleep(1);
        P(sem_id, 0);  // Re-acquire mutex
    }

    // Copy message to buffer
    strncpy(shm->messages[shm->write_index], message, MESSAGE_SIZE - 1);
    shm->messages[shm->write_index][MESSAGE_SIZE - 1] = '\0';
    shm->write_index = (shm->write_index + 1) % MAX_MESSAGES;
    shm->message_count++;

    V(sem_id, 0);  // Unlock mutex
    V(sem_id, 1);  // Signal message available

    shmdt(shm);
    printf("Sent: %s\n", message);
}

int main() {
    printf("Sender Process Started (PID: %d)\n", getpid());
    
    int shm_id = create_shared_memory();
    int sem_id = create_semaphores();

    // Initialize shared memory if we're the first process
    struct shared_memory *shm = shmat(shm_id, NULL, 0);
    if (shm->message_count == 0) {
        shm->read_index = 0;
        shm->write_index = 0;
        shm->message_count = 0;
    }
    shmdt(shm);

    // Send some messages
    for (int i = 1; i <= 5; i++) {
        char message[MESSAGE_SIZE];
        snprintf(message, sizeof(message), "Message %d from sender", i);
        send_message(shm_id, sem_id, message);
        sleep(2);  // Wait 2 seconds between messages
    }

    // Send termination message
    send_message(shm_id, sem_id, "END");
    
    printf("Sender process finished.\n");
    return 0;
}

