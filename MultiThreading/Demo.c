#include <stdio.h>
#include <pthread.h>

// Function executed by the first thread
void *threadFunction1(void *arg) {
    for (int i = 1; i <= 5; ++i) {
        printf("Thread 1: %d\n", i);
    }
    pthread_exit(NULL);
}

// Function executed by the second thread
void *threadFunction2(void *arg) {
    for (int i = 1; i <= 5; ++i) {
        printf("Thread 2: %d\n", i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Create the first thread
    if (pthread_create(&thread1, NULL, threadFunction1, NULL) != 0) {
        perror("Error creating thread 1");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL, threadFunction2, NULL) != 0) {
        perror("Error creating thread 2");
        return 2;
    }

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
