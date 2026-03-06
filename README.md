# Operating_System
Round Robin CPU Scheduling Simulation (C)

Author

V K Parthip

Vimal Jyothi Engineering College

File

"rr.c"

Description

This project implements the Round Robin CPU Scheduling Algorithm in C.
The program simulates how an operating system schedules multiple processes using a fixed time quantum.

It accepts process details such as Process ID, Arrival Time, and Burst Time, then calculates:

- Waiting Time (WT)
- Turnaround Time (TAT)
- Average Waiting Time
- Average Turnaround Time

Round Robin scheduling ensures fairness by giving each process an equal share of CPU time in cyclic order.

Input Format

Number of Processes
PID ArrivalTime BurstTime
PID ArrivalTime BurstTime
...
QuantumTime

Example Input

4
P1 0 5 
P2 1 4
P3 2 2
P4 3 1
2

Output

The program prints the waiting time, turnaround time, and their averages.

Example Output

Waiting Time:
P1 7
P2 6
P3 2
P4 5

Turnaround Time:
P1 12
P2 10
P3 4
P4 6

Average Waiting Time: 5.00
Average Turnaround Time: 8.00

Algorithm Used

Round Robin Scheduling

1. Read process information.
2. Sort processes based on arrival time.
3. Use a queue to manage process execution.
4. Each process runs for the given quantum time.
5. If a process is not finished, it is placed back in the queue.
6. Continue until all processes complete execution.

How to Compile

gcc rr.c -o rr

How to Run

./rr

Concepts Used

- Structures in C
- Arrays
- Queue implementation
- CPU Scheduling Algorithms
- Waiting Time and Turnaround Time calculations
