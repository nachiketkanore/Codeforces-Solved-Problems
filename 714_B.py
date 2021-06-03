input()
a = list(set(map(int, input().split())))
a.sort()

if len(a) > 3:
    print("NO")
elif len(a) < 3:
    print("YES")
else:
    print("YES" if a[1] - a[0] == a[2] - a[1] else "NO")