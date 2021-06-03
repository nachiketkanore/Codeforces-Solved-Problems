m, n = map(int, input().split())
ans = 0

# EV(1 + 2 + ... + m) = EV(1) + EV(2) + ... = EV(m)
# EV(i) = i * prob(i)
# prob(i) = probability that i is the maximum element in [A[1], A[2], ..., A[N]]
# prob(i) = i**n - (i-1)**n
# => Inc-Exc to remove all ways where max is not i from all ways which is (i*i*i .. * i) n times

for i in range(m+1):
    ans += i * ( (i/m)**n - ((i-1)/m)**n)

print(ans)