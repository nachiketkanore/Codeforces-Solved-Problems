n = int(input())
ans = []
def get(x):
	if x == 0:
		return [0]
	ret = [t for t in range(x)] + [t for t in range(x,-1,-1)]
	return ret

spaces = n

for i in range(n+1):
	extra = [-1] * spaces
	spaces -= 1
	ans.append(extra + get(i))
LEN = len(ans)

for i in range(LEN-2,-1,-1):
	ans.append(ans[i])

for a in ans:
	for i in range(len(a)):
		if a[i] == -1:
			print(' ', end = ' ')
		else:
			print(a[i], end = '')
			if i < len(a) - 1:
				print(' ', end = '')
	print('\n', end = '')