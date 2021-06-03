T = int(input())
while T > 0:
    T -= 1
    input()
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    done = False
    for x in a:
        if x in b:
            print("YES")
            print("1 " + str(x))
            done = True
            break
    if done == False:
        print("NO")