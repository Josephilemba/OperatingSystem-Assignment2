import matplotlib.pyplot as plt

processes = ["P1", "P2", "P3", "P4"]

start_times = [0, 5, 8, 16]

burst_times = [5, 3, 8, 6]

fig, ax = plt.subplots()

ax.barh(
    processes,
    burst_times,
    left=start_times
)

ax.set_xlabel("Time")

ax.set_title("FCFS Scheduling Gantt Chart")

plt.show()