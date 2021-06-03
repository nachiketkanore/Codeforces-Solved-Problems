n, h = map(int, input().split())
heights = list(map(int, input().split()))
print(sum([1 if x <= h else 2 for x in heights]))
