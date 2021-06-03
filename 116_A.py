ans = 0
n = int(input())
curr = 0

while n > 0:
    n -= 1
    go, come = map(int, input().split())
    curr -= go
    curr += come
    ans = max(ans, curr)

print(ans)