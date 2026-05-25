# EduOS Operating System Simulator

## Module Information

- Module Code: 351 CS 2104
- Module Name: Operating Systems
- Student Name: Joseph Ilemba
- Registration Number: YOUR REG NUMBER

---

# Project Overview

EduOS is a multi-component operating system simulator developed using C and Python.

The project demonstrates important operating system concepts including:

- Process management
- Thread management
- CPU scheduling
- Interprocess communication
- Race conditions
- Deadlocks
- Synchronization
- Shared memory
- Pipes
- System integration

The project combines low-level programming in C with high-level scheduling and visualization in Python.

---

# Prerequisites

## C Requirements

- GCC Compiler
- POSIX Threads
- Linux or MinGW Environment

## Python Requirements

- Python 3.8+
- pip

---

# Installation

## Install Python Libraries

```bash
pip install -r requirements.txt
```

---

# Build Instructions

## Compile EduOS

```bash
cd c_core
make all
```

## Run EduOS

```bash
./eduos
```

## Run Scheduler

```bash
cd python_scheduler
python scheduler_sim.py --random 10
```

## Run Controller

```bash
cd controller
python main_controller.py
```

---

# Project Structure

## docs/

Contains:
- report.pdf
- screenshots
- generated charts

## c_core/

Contains:
- PCB implementation
- process manager
- thread manager
- IPC implementation
- simulator driver

## python_scheduler/

Contains:
- FCFS
- SJF
- Priority Scheduling
- Round Robin
- Gantt chart generation

## controller/

Contains:
- integration layer
- subprocess communication
- JSON monitoring

---

# Scheduling Algorithms Implemented

- FCFS
- SJF
- Priority Scheduling
- Round Robin

---

# IPC Mechanisms

- POSIX Shared Memory
- Anonymous Pipes

---

# Threading Demonstrations

- Many-to-One Model
- One-to-One Model
- Race Condition Demonstration
- Deadlock Detection and Fix

---

# Screenshots

Screenshots will be added after implementation.

---

# Valgrind Output

```text
0 errors from 0 contexts
```

---

# Challenges Encountered

## Challenge 1

Managing synchronization between multiple threads.

### Solution

Mutex locks and semaphores were implemented.

---

## Challenge 2

Handling deadlocks caused by inconsistent mutex ordering.

### Solution

A consistent lock ordering policy was used.

---

## Challenge 3

Integrating C output with Python scheduling logic.

### Solution

JSON serialization and subprocess communication were implemented.

---

# References

- Operating Systems Course Notes
- Linux man pages
- POSIX Documentation
- Python Documentation
- GeeksforGeeks OS Tutorials