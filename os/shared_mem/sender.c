#include <time.h>

#include "common.h"

char recv[100];
char send[100];

int main() {
    init();
    int flag1 = 0;
    int first_enter = 0;

    while (1) {
        struct timespec ts;
        ts.tv_sec = time(NULL) + 5;
        ts.tv_nsec = 0;
        int i = sem_timedwait(sem_empty, &ts);
        if (i == -1) {
            printf("Receiver is not responding, exiting...\n");
            break;
        }

        //sem_wait(sem_empty);
        sem_wait(sem_mutex);

        if (!first_enter) {
            first_enter = 1;
        } else {
            // listen for response
            strcpy(recv, (char *)shmp);
            printf("Received respose:%s\n", recv);
        }

        if (flag1) {
            strcpy(recv, (char *)shmp);
            printf("Response from: %s\n", recv);
            break;
        }

        printf("Send: ");
        scanf("%s", send);
        if (strcmp(send, "exit") == 0)
            flag1 = 1;
        memset((char *)shmp, '\0', 1024);
        strcpy((char *)shmp, send);

        sem_post(sem_mutex);
        sem_post(sem_full);
    }

    // release resource
    printf("Releasing resources...\n");
    sem_unlink("empty");
    sem_unlink("full");
    sem_unlink("mutex");
    shmdt(shmp);
    shmctl(shmid, IPC_RMID, NULL);
    printf("Sender closed.\n");
    exit(0);
}