for i in range(int(input())):
    n, x = map(int, input().split())
    print(1 if n <= 2 else (n - 3) // x + 2)
