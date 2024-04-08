n = input()
p = list(map(int, input().split(" ")))

a = []
for i in range(len(p)):
    a[i] = p[i - 1] - p

minV = min(a)
