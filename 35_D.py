import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

n, x = map(int, raw_input().split())
c = map(int, raw_input().split())

for i in range(n):
    c[i] = c[i] * (n - i)
    
c.sort()
ans = 0

for cost in c:
    if cost <= x:
        ans += 1
        x -= cost

print ans
