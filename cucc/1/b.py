def parse(s:str):
    m = ["1"]
    vals = [s[0]]

    for x in range(1, len(s)):
        current = s[x]
        prev = s[x - 1]

        if current == prev:
            m[-1]  = str(int(m[-1]) + 1)
        else:
            m.append("1")
            vals.append(current)

    print(''.join(vals), ''.join(m))
    return vals + m

n = int(input())
s = "42"
    
for i in range(2, n+1):
    s = parse(s)
