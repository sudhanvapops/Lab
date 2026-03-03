### What problem are we modelling?

This code models the Producer–Consumer problem, which is about coordination, not speed.

Multiple activities want to use a shared resource (the buffer)
We must prevent:
    Race conditions
    Overflow
    Underflow

So the OS provides synchronization tools.


### What is a Semaphore? (Core Theory)

A semaphore is an integer variable 
used to control access, to shared resources in concurrent systems.


Two operations:
    wait() (P operation) → request resource
    signal() (V operation) → release resource

### Types of Semaphores:

1. Binary Semaphore
Values: 0 or 1
Used for mutual exclusion
Equivalent to a mutex

2. Counting Semaphore

Values: 0 to N
Used for resource counting


### What is mutex in this program?

mutex ensures mutual exclusion — only one process can enter the critical section at a time.

### Why is this needed?

Because:

Producer and Consumer both access shared variable x
If both modify x simultaneously → race condition

1 → resource is free
0 → resource is locked

The critical section is the code that accesses shared data.
Accessing x must be protected
x--
++x

wait(&mutex) -> enter CS
signal(&mutex) -> exit CS

| Semaphore | Solves           |
| --------- | ---------------- |
| `mutex`   | Race condition   |
| `empty`   | Buffer overflow  |
| `full`    | Buffer underflow |


####

Semaphore: like yarige ivaga access kodbeku yarige beda aduna control maduthe
Mutex: single value like a mode bit either a  process is in cs or not used for mutual exclusion