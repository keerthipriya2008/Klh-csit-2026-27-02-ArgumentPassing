#include <stdio.h>
#include <pthread.h>

int counter = 0;

pthread_mutex_t lock;

void *increment_counter(void *arg)
{
    int thread_number = *(int *)arg;

    for (int i = 0; i < 100; i++)
    {
        pthread_mutex_lock(&lock);

        counter++;

        pthread_mutex_unlock(&lock);
    }

    printf("Thread %d completed.\n",
           thread_number);

    return NULL;
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;

    int number1 = 1;
    int number2 = 2;

    printf("====================================\n");
    printf("      CO6 - THREADS AND MUTEX\n");
    printf("====================================\n");

    pthread_mutex_init(&lock, NULL);

    printf("\nInitial counter: %d\n",
           counter);

    pthread_create(&thread1,
                   NULL,
                   increment_counter,
                   &number1);

    pthread_create(&thread2,
                   NULL,
                   increment_counter,
                   &number2);

    pthread_join(thread1, NULL);

    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);

    printf("\nFinal counter: %d\n",
           counter);

    printf("\nThread synchronization completed.\n");

    return 0;
}