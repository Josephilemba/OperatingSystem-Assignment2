#include "include/eduos.h"

PCB pcb_table[MAX_PROCESSES];
int pcb_count = 0;

static int next_pid = 1000;

void save_pcb_snapshot()
{
    FILE *file = fopen("pcb_snapshot.json", "w");

    if (file == NULL)
    {
        perror("Failed to open JSON file");
        return;
    }

    fprintf(file, "[\n");

    for (int i = 0; i < pcb_count; i++)
    {
        fprintf(file,
                "  {\n"
                "    \"pid\": %d,\n"
                "    \"name\": \"%s\",\n"
                "    \"state\": %d,\n"
                "    \"priority\": %d,\n"
                "    \"burst_time\": %d,\n"
                "    \"arrival_time\": %d,\n"
                "    \"remaining_time\": %d,\n"
                "    \"memory_req_kb\": %d,\n"
                "    \"thread_count\": %d\n"
                "  }",
                pcb_table[i].pid,
                pcb_table[i].name,
                pcb_table[i].state,
                pcb_table[i].priority,
                pcb_table[i].burst_time,
                pcb_table[i].arrival_time,
                pcb_table[i].remaining_time,
                pcb_table[i].memory_req_kb,
                pcb_table[i].thread_count);

        if (i < pcb_count - 1)
        {
            fprintf(file, ",");
        }

        fprintf(file, "\n");
    }

    fprintf(file, "]\n");

    fclose(file);
}

pid_t edu_fork(PCB *parent)
{
    if (pcb_count >= MAX_PROCESSES)
    {
        printf("Process table full\n");
        return -1;
    }

    PCB child = *parent;

    child.pid = next_pid++;
    child.state = READY;
    child.creation_time = time(NULL);
    child.parent_pid = parent->pid;

    pcb_table[pcb_count++] = child;

    printf("[FORK] Parent PID %d created Child PID %d\n",
           parent->pid,
           child.pid);

    save_pcb_snapshot();

    return child.pid;
}

void edu_exec(pid_t pid, char *prog_name)
{
    for (int i = 0; i < pcb_count; i++)
    {
        if (pcb_table[i].pid == pid)
        {
            strcpy(pcb_table[i].name, prog_name);

            pcb_table[i].burst_time = 10;
            pcb_table[i].remaining_time = 10;

            printf("[EXEC] PID %d executing %s\n",
                   pid,
                   prog_name);

            save_pcb_snapshot();

            return;
        }
    }

    printf("Process not found\n");
}

int edu_wait(pid_t parent_pid)
{
    printf("[WAIT] Parent PID %d waiting...\n",
           parent_pid);

    for (int i = 0; i < pcb_count; i++)
    {
        if (pcb_table[i].parent_pid == parent_pid)
        {
            while (pcb_table[i].state != TERMINATED)
            {
            }

            return pcb_table[i].exit_code;
        }
    }

    return -1;
}

void edu_exit(pid_t pid, int exit_code)
{
    for (int i = 0; i < pcb_count; i++)
    {
        if (pcb_table[i].pid == pid)
        {
            pcb_table[i].state = TERMINATED;
            pcb_table[i].exit_code = exit_code;

            printf("[EXIT] PID %d terminated with code %d\n",
                   pid,
                   exit_code);

            save_pcb_snapshot();

            return;
        }
    }
}

void edu_ps()
{
    printf("\n================ PROCESS TABLE ================\n");

    printf("%-8s %-15s %-10s %-10s\n",
           "PID",
           "NAME",
           "STATE",
           "PRIORITY");

    for (int i = 0; i < pcb_count; i++)
    {
        printf("%-8d %-15s %-10d %-10d\n",
               pcb_table[i].pid,
               pcb_table[i].name,
               pcb_table[i].state,
               pcb_table[i].priority);
    }

    printf("================================================\n");
}