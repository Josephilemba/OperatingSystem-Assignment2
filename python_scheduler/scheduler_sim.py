class Process:
    def __init__(self, pid, burst_time):
        self.pid = pid
        self.burst_time = burst_time


def fcfs_scheduler(processes):

    current_time = 0

    print("\nFIRST COME FIRST SERVE SCHEDULING\n")

    for process in processes:

        print(
            f"Process {process.pid} executed from "
            f"{current_time} to "
            f"{current_time + process.burst_time}"
        )

        current_time += process.burst_time


process_list = [
    Process(1, 5),
    Process(2, 3),
    Process(3, 8),
    Process(4, 6)
]

fcfs_scheduler(process_list)