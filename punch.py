#!/usr/bin/env python3

T = int(input())

for t in range(1, T+1):
    R, C = map(int, input().split())

    print("Case #{}:" .format(t))
    for row in range(R*2+1):
        line = ""
        if row < 2:
            line += ".."

        C_adj = C
        if line == "..":
            C_adj = C - 1

        boundary = row % 2 == 0

        for col in range(C_adj):
            if boundary:
                line += "+-"
            else:
                line += "|."

        if boundary:
            line += "+"
        else:
            line += "|"

        print(line)
