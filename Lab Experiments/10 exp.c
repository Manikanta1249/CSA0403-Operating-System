#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message {
    long type;
    char text[100];
};

int main() {
    key_t key = ftok("msgfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct message msg;

    msg.type = 1;
    strcpy(msg.text, "Hello using Message Queue");

    msgsnd(msgid, &msg, sizeof(msg.text), 0);
    printf("Message sent: %s\n", msg.text);

    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);
    printf("Message received: %s\n", msg.text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
