### What problem does this program solve?

This program implements the Banker’s Algorithm, which is used for deadlock avoidance in Operating Systems.

The OS decides whether it is safe to grant resources to processes such that the system never enters a deadlock.

Before granting resources, the OS checks:
If I give these resources now, can the system still complete all processes in some order?
If YES → system is in a safe state
If NO → request is denied (unsafe → potential deadlock)


### Core idea of Banker’s Algorithm (theory)

Think of the OS as a banker:
Processes request resources (loans)
Banker grants them only if the system remains safe

A system is safe if there exists at least one execution order (safe sequence) such that:
    Every process can finish
    Each process only needs resources that are:
    Already available or
    Released by previously completed processes
    If no such order exists, the system is unsafe.

| Name          | Meaning                                 |
| ------------- | --------------------------------------- |
| `avail[m]`    | Currently available resources           |
| `max[n][m]`   | Maximum resources each process may need |
| `alloc[n][m]` | Resources currently allocated           |
| `need[n][m]`  | Remaining need = `max - alloc`          |
| `finish[n]`   | Whether process can finish              |
| `safeSeq[n]`  | Safe execution order                    |


## Safe state

A system is in a safe state if: 
    there exists at least one order (safe sequence) in which all processes can finish execution without deadlock.


Allocation Matrix: Resources currently allocated to each process.
Maximum Matrix: Maximum resources a process may ever request.
Need Matrix: Remaining resources required by a process to finish.

Formula: Need = Max − Allocation

Available Vector: Resources currently available in the system.
Finish Array: Indicates whether a process has completed.


### Step-by-step logic (very important)

Step 1: Initialize


## Main function (flow summary)
Input → Calculate Need → Check Safety → Print Result


Why this algorithm avoids deadlock
Resources are granted only if safety is guaranteed
OS never enters an unsafe state
Deadlock is prevented, not detected