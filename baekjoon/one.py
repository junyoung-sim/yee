while True:
    n = int(input())
    num = "1"
    while int(num) % n != 0:
        num += "1"
    print(len(num))
