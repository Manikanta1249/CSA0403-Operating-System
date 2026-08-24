#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int data = 0;
int readers = 0;

sem_t mutex, write_lock;

void *reader(void *arg) {
    sem_wait(&mutex);
    readers++;

    if (readers == 1)
        sem_wait(&write_lock);

    sem_post(&mutex);

    printf("Reader reads data: %d\n", data);

    sem_wait(&mutex);
    readers--;

    if (readers == 0)
        sem_post(&write_lock);

    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg) {
    sem_wait(&write_lock);

    data++;
    printf("Writer writes data: %d\n", data);

    sem_post(&write_lock);

    return NULL;
}

int main() {
    pthread_t r1, r2, w1;

    sem_init(&mutex, 0, 1);
    sem_init(&write_lock, 0, 1);

    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&r2, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    sem_destroy(&mutex);
    sem_destroy(&write_lock);

    return 0;
}
