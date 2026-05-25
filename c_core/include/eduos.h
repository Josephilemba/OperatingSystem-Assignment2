#ifndef EDUOS_H
#define EDUOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PROCESSES 100

#define NEW 0
#define READY 1
#define RUNNING 2
#define WAITING 3
#define TERMINATED 4

typedef struct
{
    pid_t pid;
    char name[64];
    int state;
    int priority;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int memory_req_kb;
    int thread_count;
    time_t creation_time;

    int parent_pid;
    int exit_code;

} PCB;

extern PCB pcb_table[MAX_PROCESSES];
extern int pcb_count;


pid_t edu_fork(PCB *parent);

void edu_exec(pid_t pid, char *prog_name);

int edu_wait(pid_t parent_pid);

void edu_exit(pid_t pid, int exit_code);

void edu_ps();

void save_pcb_snapshot();

#endif