#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define MSGSZ     128

struct message_buf {
    long mtype;
    char mtext[MSGSZ];
};

int main(int argc, char** argv)
{
    int msqid;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    message_buf sbuf;
    size_t buf_length;

    key = 10;

    printf("Calling msgget with key %#x and flag %#o\n", key, msgflg);

    if ((msqid = msgget(key, msgflg )) < 0) {
        perror("msgget");
        return 1;
    }
    else
        printf("msgget: msgget succeeded: msqid = %d\n", msqid);


    sbuf.mtype = 1;

    printf("msgget: msgget succeeded: msqid = %d\n", msqid);

    strcpy(sbuf.mtext, "I am in the queue?");

    printf("msgget: msgget succeeded: msqid = %d\n", msqid);

    buf_length = strlen(sbuf.mtext) + 1 ;

    if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
        printf ("%d, %lu, %s, %zu\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
        perror("msgsnd");
        return 1;
    }

    else
        printf("Message: \"%s\" Sent\n", sbuf.mtext);

    return 0;
}
