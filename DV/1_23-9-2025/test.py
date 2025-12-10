n = int(input("Enter N: "))

def F(n):

    if(n == 0): return 0
    if(n==1): return 1

    return F(n-1) + F(n-2)

if (n<0):
        print(f"Input {n} should be greater than 0")
        exit(1)
        
F(n)