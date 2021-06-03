n = int(raw_input())
a = map(int, raw_input().split())

ans = 0

for mx in range(0, 32):
    curr = 0
    for val in a:
        if val > mx:
            curr = 0
        else:
            curr += val
            ans = max(ans, curr - mx)
            curr = max(curr, 0)
print ans