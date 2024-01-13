#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>

sem_t *sem_empty;
sem_t *sem_full;
sem_t *sem_mutex;

int shmid;
void *shmp;

void init() {
    sem_empty = sem_open("empty", O_CREAT, 0666, 1);  // init as available
    sem_full = sem_open("full", O_CREAT, 0666, 0);    // init as unavailable
    sem_mutex = sem_open("mutex", O_CREAT, 0666, 1);  // init as unlocked

    shmid = shmget(99, 1024, 0666 | IPC_CREAT);  // create shared memory marked 99, 1024byte
    if (shmid == -1) {                           // if failed to get shared  memory
        perror("shmget");
        exit(-1);
    }
    shmp = shmat(shmid, NULL, 0);
    if (shmp == (void *)-1) {  // if failed to map shared memory
        perror("shmp");
        exit(-1);
    }
}