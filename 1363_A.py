t = int(raw_input())
while t > 0:
	t -= 1
	n,x = map(int, raw_input().split())
	a = map(int, raw_input().split())
	even, odd = 0,0
	for val in a:
		if val % 2 == 0:
			even += 1
		else:
			odd += 1

	ans = False

	for i in range(x + 1):
		oddcnt = i
		evencnt = x - i
		if oddcnt <= odd and evencnt <= even:
			sum = oddcnt * 1 + evencnt * 0
			sum = sum % 2
			if sum == 1:
				ans = True
	if ans:
		print "Yes"
	else:
		print "No"