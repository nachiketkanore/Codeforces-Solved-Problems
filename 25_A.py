input()
a = list(map(int, input().split()))
even = sum(1 for x in a if x % 2 == 0)
odd = sum(1 for x in a if x % 2 == 1)
for _ in range(len(a)):
    if a[_] % 2 == 1 and odd == 1:
        print(_+1)
        exit()
    if a[_] % 2 == 0 and even == 1:
        print(_+1)
        exit()