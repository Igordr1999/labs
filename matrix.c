import random


def reverse(a, n):
    c = a[0][::-1]
    d = a[n - 1][::-1]
    a[0] = d
    a[n - 1] = c

    output(a, message="\nReverse array:")
    return a


def my_rand(a, n, min_range=100, max_range=999):
    for i in range(n):
        for j in range(n):
            a[i][j] = random.randint(min_range, max_range)

    output(a, message="Start random array:")
    return a


def mini_array(a, n, minimal=1000):
    x = 0
    y = 0
    for i in range(n):
        for j in range(n):
            if a[i][j] < minimal:
                minimal = a[i][j]
                x = i
                y = j
    del a[x]
    for i in range(n - 1):
        del a[i][y]

    output(a, message="\nMini array:")
    return a


def multiplication(a, n):
    q = int(input("\nInput your number of rows: "))
    b = []
    for i in range(q):
        b.append([int(j) for j in input().split()])

    rows_A = len(a)
    cols_A = len(a[0])
    rows_B = len(b)
    cols_B = len(b[0])

    if cols_A != rows_B:
        print("Cannot multiply the two matrices. Incorrect dimensions.")
        return

    # Create the result matrix
    # Dimensions would be rows_A x cols_B
    c = [[0 for row in range(cols_B)] for col in range(rows_A)]

    for i in range(rows_A):
        for j in range(cols_B):
            for k in range(cols_A):
                c[i][j] += a[i][k] * b[k][j]

    output(c, message="\nYour end's array:")


def output(a, message="No message"):
    print(message)
    for row in a:
        print(' '.join([str(elem) for elem in row]))


def main():
    n = 4   # the size of square array
    min_range = 100
    max_range = 999
    a = [[0] * n for i in range(n)]

    a = my_rand(a, n, min_range=min_range, max_range=max_range)
    a = reverse(a, n)
    a = mini_array(a, n, minimal=max_range+1)
    multiplication(a, n)

main()
