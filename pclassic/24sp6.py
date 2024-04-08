t = int(input())


def getnew(l):
    if len(l) == 1:
        return l

    r = []
    for i in range(1, len(l)):
        if l[i - 1] <= l[i]:
            r.append(l[i - 1])
        if i == len(l) - 1:
            r.append(l[i])
    return r

for z in range(t):
    nstages = int(input())
    x = list(map(int, input().split()))
    v = list(map(int, input().split()))

    prev = v
    while prev != getnew(prev):
        prev = getnew(prev)
        
        
    
    print(len(prev))

        