t = int(raw_input())
while t > 0:
	t -= 1
	n = int(raw_input())
	s = str(raw_input())
	tt = s
	s = []
	for ch in tt:
		s += ch
	ans = 0
	for x in range(n):
		pres = False
		idx = []
		for i in range(n - 1):
			if s[i] == 'A' and s[i + 1] == 'P':
				idx.append(i)
				pres = True
		if pres:
			ans += 1
			for id in idx:
				s[id + 1] = 'A'
	print(ans)