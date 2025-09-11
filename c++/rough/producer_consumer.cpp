#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
// Avoid using "using namespace std;" in this case
// to prevent naming conflicts.

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t sem_empty, sem_full;
pthread_mutex_t mutex;

void* producer(void* arg) {
    int item;
    for (int i = 0; i < 5; i++) {
        item = i + 1;
        // Use the renamed semaphore variable
        sem_wait(&sem_empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        std::cout << "Producer produced: " << item << std::endl;
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&sem_full);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    int item;
    for (int i = 0; i < 5; i++) {
        sem_wait(&sem_full);
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        std::cout << "Consumer consumed: " << item << std::endl;
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        // Use the renamed semaphore variable
        sem_post(&sem_empty);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t pThread, cThread;
    // Use the renamed semaphore variables
    sem_init(&sem_empty, 0, BUFFER_SIZE);
    sem_init(&sem_full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&pThread, NULL, producer, NULL);
    pthread_create(&cThread, NULL, consumer, NULL);

    pthread_join(pThread, NULL);
    pthread_join(cThread, NULL);

    // Use the renamed semaphore variables
    sem_destroy(&sem_empty);
    sem_destroy(&sem_full);
    pthread_mutex_destroy(&mutex);

    return 0;
}