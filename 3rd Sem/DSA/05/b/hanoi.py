def tower_of_hanoi(n, from_rod, aux_rod, to_rod, depth=0):
    indent = "    " * depth  # indentation for visualizing recursion depth

    print(f"{indent}Call: tower_of_hanoi({n}, {from_rod}, {aux_rod}, {to_rod})")

    if n == 0:
        print(f"{indent}Return (n == 0)")
        return

    # Move top n-1 from 'from' to 'aux'
    tower_of_hanoi(n - 1, from_rod, to_rod, aux_rod, depth + 1)

    # Move nth disc from 'from' to 'to'
    print(f"{indent}Move disc {n} from {from_rod} to {to_rod}")

    # Move n-1 from 'aux' to 'to'
    tower_of_hanoi(n - 1, aux_rod, from_rod, to_rod, depth + 1)


def total_moves(n):
    return 2**n - 1


# MAIN
discs = int(input("Enter number of discs: "))
print("\n--- TRACE AND MOVES ---\n")
tower_of_hanoi(discs, 'A', 'B', 'C')
print(f"\nTotal moves = {total_moves(discs)}")


