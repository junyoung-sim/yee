a, b, c = list(map(int, input().split()))

if (a == 0) or (b == 0) or (c == 0):
    print("YES")
elif (a * b == c) or  (b * c == a) or (a * c == b):
    print("YES")
else:
    print("NO")