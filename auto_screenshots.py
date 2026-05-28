import pyautogui
import time
import os

os.makedirs("docs/screenshots", exist_ok=True)

print("Starting screenshots in 5 seconds...")

time.sleep(5)

screenshots = [

    "compile_success.png",
    "fork_processes.png",
    "process_table.png",
    "race_condition.png",
    "mutex_demo.png",
    "semaphore_demo.png",
    "pipe_demo.png",
    "shared_memory_demo.png",
    "all_schedulers.png"
]

for name in screenshots:

    image = pyautogui.screenshot()

    image.save(f"docs/screenshots/{name}")

    print(f"Saved {name}")

    time.sleep(5)

print("All screenshots completed.")