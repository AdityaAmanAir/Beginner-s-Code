#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <signal.h>

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

int get_shared_memory() {
    key_t key = ftok(".", 'S');
    int shm_id = shmget(key, sizeof(struct shared_memory), 0666);
    if (shm_id == -1) {
        perror("shmget failed - is sender running?");
        exit(1);
    }
    return shm_id;
}

int get_semaphores() {
    key_t key = ftok(".", 'T');
    int sem_id = semget(key, 2, 0666);
    if (sem_id == -1) {
        perror("semget failed - is sender running?");
        exit(1);
    }
    return sem_id;
}

void receive_message(int shm_id, int sem_id) {
    struct shared_memory *shm = shmat(shm_id, NULL, 0);
    if (shm == (void*)-1) {
        perror("shmat in receive failed");
        exit(1);
    }

    P(sem_id, 1);  // Wait for message available
    P(sem_id, 0);  // Lock mutex

    char message[MESSAGE_SIZE];
    strncpy(message, shm->messages[shm->read_index], MESSAGE_SIZE);
    shm->read_index = (shm->read_index + 1) % MAX_MESSAGES;
    shm->message_count--;

    V(sem_id, 0);  // Unlock mutex

    shmdt(shm);
    printf("Received: %s\n", message);
    
    // Check for termination message
    if (strcmp(message, "END") == 0) {
        printf("Receiver shutting down.\n");
        exit(0);
    }
}

void cleanup(int sig) {
    printf("\nReceiver interrupted. Cleaning up...\n");
    exit(0);
}

int main() {
    printf("Receiver Process Started (PID: %d)\n", getpid());
    printf("Waiting for messages...\n");
    
    signal(SIGINT, cleanup);
    
    int shm_id = get_shared_memory();
    int sem_id = get_semaphores();

    // Continuously receive messages
    while (1) {
        receive_message(shm_id, sem_id);
    }

    return 0;
}
