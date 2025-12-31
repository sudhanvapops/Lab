### FIFO

Logic:

Initialize all frames to -1
For each page:
Check if page is present

If fault:
Replace page at index
Move index circularly
Increment fault count
Print frame status after each step

