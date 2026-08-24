#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    printf("Thread is running.\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;

    /* (i) Create */
    pthread_create(&t1, NULL, thread_function, NULL);
    pthread_create(&t2, NULL, thread_function, NULL);
    printf("Threads created successfully.\n");

    /* (iii) Equal */
    if (pthread_equal(t1, t2))
        printf("Both threads are equal.\n");
    else
        printf("Both threads are not equal.\n");

    /* (ii) Join */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Threads joined successfully.\n");

    /* (iv) Exit */
    pthread_exit(NULL);

    return 0;
}
