import os

print("EduOS Python Controller")

print("\nLaunching FCFS Scheduler...\n")

current_dir = os.path.dirname(__file__)

scheduler_path = os.path.join(
    current_dir,
    "..",
    "python_scheduler",
    "scheduler_sim.py"
)

os.system(f'python "{scheduler_path}"')