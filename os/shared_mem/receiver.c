#include "common.h"

char recv[100];
char send[100];

int main() {
    init();
    int flag = 0;

    while (1) {
        sem_wait(sem_full);   // wait for available resourse
        sem_wait(sem_mutex);  // wait for unlock

        strcpy(recv, (char *)shmp);  // copy from shared memnory
        printf("Received :%s\n", recv);

        if (strcmp(recv, "exit") == 0) {
            strcpy(send, "over");
            memset((char *)shmp, '\0', 1024);  // clear shared memory
            strcpy((char *)shmp, send);        // copy to shared memory
            flag = 1;
        } else {
            snprintf(send, sizeof(send), " Received: %s", recv);  // respond to sender
            strcpy((char *)shmp, send);
        }

        sem_post(sem_empty);  // release resource
        sem_post(sem_mutex);  // unlock

        if (flag)
            break;
    }

    shmdt(shmp);  // release shared memory
    printf("Receiver closed.\n");
    exit(0);
}