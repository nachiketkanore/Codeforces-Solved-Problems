t = int(raw_input())

while t > 0:
    t -= 1
    n, m, k = map(int, raw_input().split())
    winner = min(m, n//k)
    m -= winner
    winner2 = min(n//k, m//(k - 1))
    if m % (k - 1) > 0:
        winner2 = min(winner2 + 1, n//k)
    ans = winner - winner2
    print ans