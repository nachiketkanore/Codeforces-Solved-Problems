n, m, k = map(int, raw_input().split())
mat = [[0] * m] * n
ans = 0
for i in range(n):
	mat[i] = [ch for ch in str(raw_input())]

for i in range(n):
	curr = 0
	lens = []
	for j in range(m):
		if mat[i][j] == '.':
			curr += 1
		else :
			if curr > 0:
				lens.append(curr)
			curr = 0
	if curr > 0:
		lens.append(curr)
	for len in lens:
		if len >= k:
			ans += len - k + 1

for j in range(m):
	curr = 0
	lens = []
	for i in range(n):
		if mat[i][j] == '.':
			curr += 1
		else :
			if curr > 0:
				lens.append(curr)
			curr = 0
	if curr > 0:
		lens.append(curr)
	for len in lens:
		if len >= k:
			ans += len - k + 1
if k == 1:
	ans = ans // 2
print (ans)