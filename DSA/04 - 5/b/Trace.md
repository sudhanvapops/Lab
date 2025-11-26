--- TRACE AND MOVES ---

Call: tower_of_hanoi(3, A, B, C)
    Call: tower_of_hanoi(2, A, C, B)
        Call: tower_of_hanoi(1, A, B, C)
            Call: tower_of_hanoi(0, A, C, B)
            Return (n == 0)
        Move disc 1 from A to C
            Call: tower_of_hanoi(0, B, A, C)
            Return (n == 0)
    Move disc 2 from A to B
        Call: tower_of_hanoi(1, C, A, B)
            Call: tower_of_hanoi(0, C, B, A)
            Return (n == 0)
        Move disc 1 from C to B
            Call: tower_of_hanoi(0, A, C, B)
            Return (n == 0)
Move disc 3 from A to C
    Call: tower_of_hanoi(2, B, A, C)
        Call: tower_of_hanoi(1, B, C, A)
            Call: tower_of_hanoi(0, B, A, C)
            Return (n == 0)
        Move disc 1 from B to A
            Call: tower_of_hanoi(0, C, B, A)
            Return (n == 0)
    Move disc 2 from B to C
        Call: tower_of_hanoi(1, A, B, C)
            Call: tower_of_hanoi(0, A, C, B)
            Return (n == 0)
        Move disc 1 from A to C
            Call: tower_of_hanoi(0, B, A, C)
            Return (n == 0)

Total moves = 7