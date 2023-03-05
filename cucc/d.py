def permutations(s):
    res = []
    for i in range(len(s)):
        res.append(s[0:i] + [i+1:len(s)])
    return res

def f():
    if len()
    ans = []
    read = input().split("\n")
    longest = max(read, key=len)
    subset = permutations(longest)
    count = 0
    for i in range(len(subset)): #doesn't work yet
        if subset[i] == read[i]:
            count += 1
    if count > 0 and count < len(subset):
        ans.append("WARNING")
    elif count == len(subset):
        ans.append("ERROR")
    else:
        ans.append("OK")