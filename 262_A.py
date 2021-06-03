n, k = map(int, input().split())
a = input().split()
print(sum([1 if str(x).count("4") + str(x).count("7") <= k else 0 for x in a]))