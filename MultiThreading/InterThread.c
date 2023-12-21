#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int shared_data = 0;

void* producer(void* arg) {
    for (int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&mutex);
        shared_data = i;
        printf("Produced: %d\n", shared_data);
        pthread_cond_signal(&cond); // Signal consumer that data is ready
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&mutex);
        while (shared_data == -1) {
            pthread_cond_wait(&cond, &mutex); // Wait for data to be produced
        }
        printf("Consumed: %d\n", shared_data);
        shared_data = -1;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}

