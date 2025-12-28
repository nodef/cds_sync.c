#define CDS_SYNC_IMPLEMENTATION
#include <cds_sync.h>
#include <stdio.h>
#include <threads.h>
#include <time.h>

cds_sync_monitor_t monitor;
int data_ready = 0;

int producer(void* arg) {
    struct timespec ts = {1, 0};
    thrd_sleep(&ts, NULL); // Simulate data preparation
    cds_sync_monitor_lock(&monitor);
    data_ready = 1;
    printf("Producer: Data is ready.\n");
    cds_sync_monitor_signal(&monitor);
    cds_sync_monitor_unlock(&monitor);
    return 0;
}

int consumer(void* arg) {
    cds_sync_monitor_lock(&monitor);
    while (!data_ready) {
        cds_sync_monitor_unlock_and_wait(&monitor);
    }
    printf("Consumer: Consuming data.\n");
    cds_sync_monitor_unlock(&monitor);
    return 0;
}

int main() {
    thrd_t prod_thread, cons_thread;

    cds_sync_monitor_init(&monitor);

    thrd_create(&prod_thread, producer, NULL);
    thrd_create(&cons_thread, consumer, NULL);

    thrd_join(prod_thread, NULL);
    thrd_join(cons_thread, NULL);

    cds_sync_monitor_destroy(&monitor);

    return 0;
}
