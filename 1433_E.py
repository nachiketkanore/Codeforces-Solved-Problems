n = int(input())

def fact(n):
    if n == 0:
        return 1
    return n * fact(n - 1)

def choose(n, r):
    if r > n:
        return 0
    return fact(n) // (fact(n - r) * fact(r))

half = n // 2

ans = choose(n, half) // 2

ans = ans * fact(half - 1) * fact(half - 1)

print (ans)