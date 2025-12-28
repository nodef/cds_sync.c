#define CDS_SYNC_IMPLEMENTATION
#include <cds_sync.h>
#include <stdio.h>
#include <threads.h>

#define NUM_THREADS 4
#define INCREMENTS 1000

cds_sync_futex_t futex;
int shared_counter = 0;

int increment_counter(void* arg) {
    for (int i = 0; i < INCREMENTS; i++) {
        cds_sync_futex_lock(&futex);
        shared_counter++;
        cds_sync_futex_unlock(&futex);
    }
    return 0;
}

int main() {
    thrd_t threads[NUM_THREADS];

    cds_sync_futex_init(&futex);

    for (int i = 0; i < NUM_THREADS; i++) {
        thrd_create(&threads[i], increment_counter, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        thrd_join(threads[i], NULL);
    }

    cds_sync_futex_destroy(&futex);

    printf("Final counter value: %d\n", shared_counter);
    return 0;
}
