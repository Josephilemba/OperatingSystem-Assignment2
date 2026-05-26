CC = gcc

CFLAGS = -Wall -Wextra -pthread -std=c11

TARGET = eduos

SRC = process_manager.c thread_manager.c ipc_module.c main_sim.c

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	del /Q *.exe *.o 2>nul

race:
	$(CC) $(CFLAGS) -DRACE_MODE -o race_demo main_sim.c process_manager.c

fixed:
	$(CC) $(CFLAGS) -o fixed_demo main_sim.c process_manager.c

memcheck:
	valgrind --leak-check=full ./$(TARGET)