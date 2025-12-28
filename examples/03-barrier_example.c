#define CDS_SYNC_IMPLEMENTATION
#include <cds_sync.h>
#include <stdio.h>
#include <threads.h>

#define NUM_THREADS 4

cds_sync_barrier_t barrier;

int thread_task(void* arg) {
    int thread_id = *(int*)arg;
    printf("Thread %d: Reached the barrier.\n", thread_id);
    cds_sync_barrier_enter(&barrier);
    printf("Thread %d: Passed the barrier.\n", thread_id);
    cds_sync_barrier_exit(&barrier);
    return 0;
}

int main() {
    thrd_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    cds_sync_barrier_init(&barrier, NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        thrd_create(&threads[i], thread_task, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        thrd_join(threads[i], NULL);
    }

    cds_sync_barrier_destroy(&barrier);

    return 0;
}
