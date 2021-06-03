a = map(int, raw_input().split())
seq = raw_input().split()

def find_min(id, now):
    n = len(now)
    if n == 1:
        return now[0]
    
    ans = 10 ** 18
    
    for i in range(n):
        for j in range(n):
            if i != j:
                next = []
                if seq[id] == '+':
                    next.append(now[i] + now[j])
                else :
                    next.append(now[i] * now[j])
                for k in range(n):
                    if k != i and k != j:
                        next.append(now[k])
                value = find_min(id + 1, next)
                ans = min(ans, value)
    return ans
            
    

print find_min(0, a)