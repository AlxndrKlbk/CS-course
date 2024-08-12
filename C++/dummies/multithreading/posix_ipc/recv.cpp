#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

#define MSGSZ     128

struct message_buf {
    long mtype;
    char mtext[MSGSZ];
};

int main(int argc, char** argv)
{
    int msqid;
    key_t key;
    message_buf  rbuf;

    key = 10;

    if ((msqid = msgget(key, 0666)) < 0) {
        perror("msgget");
        return 1;
    }

    if (msgrcv(msqid, &rbuf, MSGSZ, 1, 0) < 0) {
        perror("msgrcv");
        return 1;
    }

    printf("%s\n", rbuf.mtext);
    return 0;
}
