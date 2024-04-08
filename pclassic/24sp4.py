n = int(input())
ntowns = int(input())
towns = list(map(int, input().split()))
cap = int(input())
tf = int(input())
tw = int(input())

towns.sort()

lastTowns = sum(towns[-cap:]) * tf
firstTowns = sum(towns[:-cap]) * tw

print(lastTowns + firstTowns)
