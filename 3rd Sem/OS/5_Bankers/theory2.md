work is a temporary copy of available resources
We simulate resource allocation without changing the real system

Step 2: Initialize finish array all to 0
finish[i] = 0 → process i has not finished yet
We’ll mark it 1 once it can safely complete

Step 3: Main loop — try to finish all processes
Keep searching until all processes are completed
count = number of finished processes

S4: Try to find at least ONE executable process
Tracks whether we found any process that can execute in this round
If none is found → system is unsafe

Step 6: Check if process i can execute
    critical Banker’s Check:
    Can this process get all remaining resources it needs?
    If any resource type is insufficient, break
    If loop completes (j == m), all needs can be satisfied

Step 7: If process can execute
if (j == m)    // can execute
This process can complete without waiting
It is safe to schedule it now

