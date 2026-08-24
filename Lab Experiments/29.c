#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void *process(void *arg) {
    int id = *(int *)arg;

    sem_wait(&semaphore);

    printf("Process %d is in critical section.\n", id);

    for (int i = 1; i <= 3; i++)
        printf("Process %d working...\n", id);

    printf("Process %d leaving critical section.\n", id);

    sem_post(&semaphore);

    return NULL;
}

int main() {
    pthread_t p1, p2;
    int id1 = 1, id2 = 2;

    sem_init(&semaphore, 0, 1);

    pthread_create(&p1, NULL, process, &id1);
    pthread_create(&p2, NULL, process, &id2);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    sem_destroy(&semaphore);

    return 0;
}
