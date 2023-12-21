#include <stdio.h>
#include <pthread.h>

#define BUFFER_SIZE 1

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int buffer[BUFFER_SIZE];
int buffer_index = -1;

void* producer(void* arg) {
    for (int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&mutex);

        // Wait until buffer is empty
        while (buffer_index == BUFFER_SIZE - 1) {
            pthread_cond_wait(&cond, &mutex);
        }

        // Produce data
        buffer[++buffer_index] = i;
        printf("Produced: %d\n", buffer[buffer_index]);

        // Signal consumer that data is ready
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

void* consumer(void* arg) {
    for (int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&mutex);

        // Wait until buffer is not empty
        while (buffer_index == -1) {
            pthread_cond_wait(&cond, &mutex);
        }

        // Consume data
        int consumed_data = buffer[buffer_index--];
        printf("Consumed: %d\n", consumed_data);

        // Signal producer that buffer is not full
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
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

