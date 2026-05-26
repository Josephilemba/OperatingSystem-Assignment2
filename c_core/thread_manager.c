#include "include/eduos.h"
#include <pthread.h>

int shared_counter = 0;

pthread_mutex_t counter_mutex;

void *race_increment(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        shared_counter++;
    }

    return NULL;
}

void *safe_increment(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&counter_mutex);

        shared_counter++;

        pthread_mutex_unlock(&counter_mutex);
    }

    return NULL;
}

void run_race_condition_demo()
{
    pthread_t t1, t2;

    shared_counter = 0;

    pthread_create(&t1, NULL, race_increment, NULL);

    pthread_create(&t2, NULL, race_increment, NULL);

    pthread_join(t1, NULL);

    pthread_join(t2, NULL);

    printf("\n[RACE CONDITION DEMO]\n");

    printf("Expected Counter: 200000\n");

    printf("Actual Counter: %d\n", shared_counter);
}

void run_mutex_demo()
{
    pthread_t t1, t2;

    shared_counter = 0;

    pthread_mutex_init(&counter_mutex, NULL);

    pthread_create(&t1, NULL, safe_increment, NULL);

    pthread_create(&t2, NULL, safe_increment, NULL);

    pthread_join(t1, NULL);

    pthread_join(t2, NULL);

    pthread_mutex_destroy(&counter_mutex);

    printf("\n[MUTEX SYNCHRONIZATION DEMO]\n");

    printf("Expected Counter: 200000\n");

    printf("Actual Counter: %d\n", shared_counter);
}
