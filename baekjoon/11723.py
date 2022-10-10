#!/usr/bin/env python3

ans = ""
group = [0 for i in range(21)]

M = int(input())
for m in range(M):
    cmd = input().split(" ")
    if cmd[0] == "add":
        group[int(cmd[1])] = 1
    elif cmd[0] == "remove":
        group[int(cmd[1])] = 0
    elif cmd[0] == "check":
        ans += str(group[int(cmd[1])]) + "\n"
    elif cmd[0] == "toggle":
        group[int(cmd[1])] = int(not group[int(cmd[1])])
    elif cmd[0] == "all":
        for n in range(1, 21):
            group[n] = 1
    else:
        for n in range(1, 21):
            group[n] = 0

print(ans)