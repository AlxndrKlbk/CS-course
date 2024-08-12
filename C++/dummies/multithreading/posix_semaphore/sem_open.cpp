#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>

#define SEMAPHORE_NAME "/my_named_semaphore"

int main(int argc, char ** argv) {
    sem_t *sem;

    if ( argc == 2 ) {
        printf("Dropping semaphore...\n");
        if ( (sem = sem_open(SEMAPHORE_NAME, 0)) == SEM_FAILED ) {
            perror("sem_open");
            return 1;
        }
        sem_post(sem);
        perror("sem_post");
        printf("Semaphore dropped.\n");
        return 0;
    }

    if ( (sem = sem_open(SEMAPHORE_NAME, O_CREAT, 0777, 0)) == SEM_FAILED ) {
        perror("sem_open");
        return 1;
    }

    printf("Semaphore is taken.\nWaiting for it to be dropped.\n");

    sem_wait(sem);
    perror("sem_wait");

    sem_close(sem);
    perror("sem_close");

    return 0;
}
