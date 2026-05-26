#include "include/eduos.h"
#include <unistd.h>
#include <string.h>

void run_pipe_demo()
{
    int fd[2];

    pid_t pid;

    char write_msg[] = "Hello from Parent Process";

    char read_msg[100];

    pipe(fd);

    pid = fork();

    if (pid > 0)
    {
        close(fd[0]);

        write(fd[1], write_msg, strlen(write_msg) + 1);

        close(fd[1]);

        wait(NULL);

        printf("\n[IPC PIPE DEMO]\n");

        printf("Parent sent message: %s\n", write_msg);
    }
    else if (pid == 0)
    {
        close(fd[1]);

        read(fd[0], read_msg, sizeof(read_msg));

        printf("Child received message: %s\n", read_msg);

        close(fd[0]);
    }
}