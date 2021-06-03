n, m = map(int, input().split())

def solve(a,b):
    ans = 0
    while a <= b:
        ans += 1
        a *= 3
        b *= 2
    return ans

print(solve(n,m))