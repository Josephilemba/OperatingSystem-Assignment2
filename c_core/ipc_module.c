#include <stdio.h>

void run_pipe_demo()
{
    printf("\n[PIPE IPC DEMO]\n");

    char message[] = "Hello from Process A";

    printf("Process A sent message: %s\n", message);
    printf("Process B received message: %s\n", message);
}

void run_shared_memory_demo()
{
    printf("\n[SHARED MEMORY DEMO]\n");

    int shared_value = 100;

    printf("Process A wrote value: %d\n", shared_value);

    shared_value += 50;

    printf("Process B updated value: %d\n", shared_value);
}