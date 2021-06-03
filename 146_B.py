def check_mask(num, mask):
    val = ''
    for d in str(num):
        if d == '4' or d == '7':
            val += d
    if str(mask) == val:
        return True
    return False

a, b = map(int, raw_input().split())

start = a + 1

while True:
    if check_mask(start, b):
        print start
        break
    start += 1