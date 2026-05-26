#include "include/eduos.h"

int main()
{
    PCB parent;

    parent.pid = 1;

    strcpy(parent.name, "init");

    parent.state = RUNNING;

    parent.priority = 0;

    parent.burst_time = 20;

    parent.arrival_time = 0;

    parent.remaining_time = 20;

    parent.memory_req_kb = 512;

    parent.thread_count = 2;

    parent.creation_time = time(NULL);

    parent.parent_pid = 0;

    parent.exit_code = 0;

    pcb_table[pcb_count++] = parent;

    printf("EduOS Simulator Starting...\n");


    pid_t child1 = edu_fork(&parent);

    pid_t child2 = edu_fork(&parent);


    edu_exec(child1, "text_editor");

    edu_exec(child2, "web_browser");


    edu_ps();


    edu_exit(child1, 0);

    edu_exit(child2, 1);


    edu_ps();

   run_race_condition_demo();

    run_mutex_demo();

    run_pipe_demo();

    printf("\nEduOS Simulation Finished.\n");

    return 0;
}