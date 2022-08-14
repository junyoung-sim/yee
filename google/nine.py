#!/usr/bin/env python3

T = int(input())

for t in range(1, T+1):
    N = input()
    digits = [int(digit) for digit in N]

    n = 9 - sum(digits) % 9

    inserted = False
    for i in range(len(digits)):
        if digits[i] > n:
            digits.insert(i, n)
            inserted = True
            break
    if not inserted:
        digits.append(n)

    print(digits)

    number = ""
    for digit in digits:
        number += str(digit)

    print("Case #{}: {}" .format(t, number))

