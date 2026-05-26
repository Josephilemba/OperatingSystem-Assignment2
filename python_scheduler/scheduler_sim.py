class Process:

    def __init__(self, pid, burst_time, priority):

        self.pid = pid
        self.burst_time = burst_time
        self.priority = priority


processes = [
    Process(1, 5, 2),
    Process(2, 3, 1),
    Process(3, 8, 4),
    Process(4, 6, 3)
]


def fcfs_scheduler(processes):

    print("\n========== FCFS SCHEDULING ==========\n")

    current_time = 0

    for process in processes:

        print(
            f"Process {process.pid} executed "
            f"from {current_time} "
            f"to {current_time + process.burst_time}"
        )

        current_time += process.burst_time


def sjf_scheduler(processes):

    print("\n========== SJF SCHEDULING ==========\n")

    current_time = 0

    sorted_processes = sorted(
        processes,
        key=lambda p: p.burst_time
    )

    for process in sorted_processes:

        print(
            f"Process {process.pid} executed "
            f"from {current_time} "
            f"to {current_time + process.burst_time}"
        )

        current_time += process.burst_time


def priority_scheduler(processes):

    print("\n========== PRIORITY SCHEDULING ==========\n")

    current_time = 0

    sorted_processes = sorted(
        processes,
        key=lambda p: p.priority
    )

    for process in sorted_processes:

        print(
            f"Process {process.pid} "
            f"(Priority {process.priority}) "
            f"executed from {current_time} "
            f"to {current_time + process.burst_time}"
        )

        current_time += process.burst_time


def round_robin_scheduler(processes, quantum=2):

    print("\n========== ROUND ROBIN SCHEDULING ==========\n")

    remaining = {
        p.pid: p.burst_time for p in processes
    }

    current_time = 0

    done = False

    while not done:

        done = True

        for process in processes:

            if remaining[process.pid] > 0:

                done = False

                execute_time = min(
                    quantum,
                    remaining[process.pid]
                )

                print(
                    f"Process {process.pid} executed "
                    f"from {current_time} "
                    f"to {current_time + execute_time}"
                )

                current_time += execute_time

                remaining[process.pid] -= execute_time


fcfs_scheduler(processes)

sjf_scheduler(processes)

priority_scheduler(processes)

round_robin_scheduler(processes)