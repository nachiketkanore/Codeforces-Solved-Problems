n = int(input())
a = list(map(int, input().split()))

ans = 1

def go(L, R):
	global ans
	if L > R:
		return
	x = [a[e] for e in range(L, R+1)]
	if x == sorted(x):
		ans = max(ans, R - L + 1) 
		return
	M = (L + R) // 2
	go(L, M)
	go(M+1, R)

go(0, n-1)

print(ans)