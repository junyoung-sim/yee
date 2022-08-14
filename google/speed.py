#!/usr/bin/env python3

def main():
    T = int(input())

    for t in range(1, T+1):
        I = input()
        P = input()

        fixable = True
        k = 0

        for i in range(len(I)):
            if P[k:].find(I[i]) != -1:
                k += P[k:].find(I[i]) + 1
            else:
                fixable = False
                break

        if fixable:
            print("Case #{}: {}" .format(t, len(P) - len(I)))
        else:
            print("Case #{}: IMPOSSIBLE" .format(t))

if __name__ == "__main__":
    main()
