This program demonstrates Inter-Process Communication (IPC) using a FIFO (Named Pipe) in UNIX/Linux.

Two separate processes communicate by sending data through a file-like pipe.

A FIFO (First In First Out) is a special file that allows one process to write data and another process to read data, in the order it was written.

Key properties:
Exists as a file in the filesystem
Used for related or unrelated processes
Unidirectional per open (read or write)

Unlike anonymous pipes (pipe()), FIFO:
Exists even after process ends
Can be opened by different programs

Writer writes data into FIFO
Reader reads data from FIFO
Kernel acts as buffer + synchronizer

