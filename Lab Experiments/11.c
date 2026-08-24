#include <stdio.h>
#include <pthread.h>

void *threadFunction(void *arg) {
    printf("Thread is running...\n");
    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, threadFunction, NULL);
    pthread_join(thread, NULL);

    printf("Main thread completed.\n");

    return 0;
}
