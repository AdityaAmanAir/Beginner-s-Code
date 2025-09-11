#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t wrt;
pthread_mutex_t mutex;
int cnt = 1, numreader = 0;

void* writer(void* arg) {
    sem_wait(&wrt);
    cnt = cnt*2;
    cout << "Writer writes: " << cnt << endl;
    sem_post(&wrt);
    return NULL;
}

void* reader(void* arg) {
    pthread_mutex_lock(&mutex);
    numreader++;
    if (numreader == 1) sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);

    cout << "Reader reads: " << cnt << endl;

    pthread_mutex_lock(&mutex);
    numreader--;
    if (numreader == 0) sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t read[5], write[5];
    sem_init(&wrt, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 3; i++) {
        pthread_create(&read[i], NULL, reader, NULL);
        pthread_create(&write[i], NULL, writer, NULL);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(read[i], NULL);
        pthread_join(write[i], NULL);
    }
    sem_destroy(&wrt);
    
    pthread_mutex_destroy(&mutex);
    return 0;
}