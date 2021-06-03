t = int(raw_input())
while t > 0:
	t -= 1
	s = [x for x in str(raw_input())]
	n = len(s)
	ones, zeros = 0, 0
	for v in s: 
		if v == '1': ones += 1 
		else : zeros += 1
	c0, c1 = 0, 0
	ans = min(ones, zeros)
	for v in s:
		if v == '1': c1 += 1
		else : c0 += 1
		cost01 = c1 + (zeros - c0)
		cost10 = c0 + (ones - c1)
		ans = min(ans, cost01, cost10)
	print ans
