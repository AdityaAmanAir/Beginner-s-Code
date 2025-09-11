#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define MEALS 2  // Number of times each philosopher eats

int state[N];
sem_t mutex, S[N];

void test(int i) {
    if (state[i] == HUNGRY &&
        state[(i+4)%N] != EATING &&
        state[(i+1)%N] != EATING) {
        state[i] = EATING;
        sleep(1);
        cout << "Philosopher " << i+1 << " is Eating" << endl;
        sem_post(&S[i]);
    }
}

void take_fork(int i) {
    sem_wait(&mutex);
    state[i] = HUNGRY;
    cout << "Philosopher " << i+1 << " is Hungry" << endl;
    test(i);
    sem_post(&mutex);
    sem_wait(&S[i]);
}

void put_fork(int i) {
    sem_wait(&mutex);
    state[i] = THINKING;
    cout << "Philosopher " << i+1 << " is Thinking" << endl;
    test((i+4)%N);
    test((i+1)%N);
    sem_post(&mutex);
}

void* philosopher(void* num) {
    int i = *(int*)num;
    for (int meal = 0; meal < MEALS; meal++) {
        sleep(1);
        take_fork(i);
        sleep(2);
        put_fork(i);
    }
    cout << "Philosopher " << i+1 << " has finished eating.\n";
    return NULL;
}

int main() {
    pthread_t tid[N];
    int phil[N];

    sem_init(&mutex, 0, 1);
    for (int i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);

    for (int i = 0; i < N; i++) {
        phil[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &phil[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    return 0;
}