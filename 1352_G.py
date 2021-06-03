for T in range(int(input())):
    n = int(input())
    if n < 4:
        print(-1)
    else:
        ans = []
        for id in range(6,n+1,2):
            ans.append(id)
        ans.reverse()
        ans.append(2)
        ans.append(4)
        for id in range(1,n+1,2):
            ans.append(id)
        for x in ans:
            print(x, end = ' ')
        print('\n', end = '')