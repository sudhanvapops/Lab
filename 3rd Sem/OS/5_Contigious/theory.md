### In Operating Systems, when multiple processes request memory, the OS must decide which memory block to assign to each process.


### First Fit

Allocate the first block that is large enough.

Idea
Scan memory blocks from the beginning
The moment a block fits → allocate it
Fast but may cause fragmentation at the start

Example:
Blocks: 100, 500, 200
Process: 120
→ Allocated to block 500 (first block that fits)

and another 380 is wasted

### Best Fit

Allocate the smallest block that is sufficient.

Idea
Search all blocks
Choose the block that leaves least leftover memory
Reduces waste, but slower (needs full scan)

### Worst Fit

Allocate the largest available block.

Idea
Give process the biggest block
Leaves large leftover spaces
Helps future large processes

Once memory is allocated, block size is reduced
This simulates internal fragmentation handling



blockSize[] → stores memory block sizes
processSize[] → stores process sizes
allocation[] → stores allocated block index for each process

nb → number of blocks
np → number of processes
allocation[i] = -1 means not allocated