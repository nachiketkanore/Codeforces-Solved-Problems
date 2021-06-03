input()
a = input().split()
b = input().split()

for i in range(1,10):
    if str(i) in a and str(i) in b:
        print(i)
        exit()

ans = str(min(a)) + str(min(b))
print(min(ans) + '' +  max(ans))