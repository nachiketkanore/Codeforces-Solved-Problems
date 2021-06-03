one, two, inf = 0, 0, 10**18
dp = [-1 for _ in range(2000)]

def go(len):
    if len < 0:
        return inf
    if len == 0:
        return 0
    
    if dp[len] != -1:
        return dp[len]
    
    cost1 = one + go(len - 1)
    cost2 = two + go(len - 2)
    dp[len] = min(cost1, cost2)
    
    return dp[len]
    

t = int(raw_input())
while t > 0:
    t -= 1
    
    dp = [-1 for _ in range(2000)]
    n, m, x, y = map(int, raw_input().split())
    one, two = x, y
    
    ans = 0
    
    for i in range(n):
        s = raw_input()
        consec = []
        len = 0
        for id in range(m):
            if s[id] == '.':
                len += 1
            else :
                if len :
                    consec.append(len)
                len = 0
        if len :
            consec.append(len)
        
        for l in consec:
            ans += go(l)
    
    print(ans)
        
    
