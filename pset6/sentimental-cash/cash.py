from cs50 import get_float

while True:
    n = get_float("Change: ")
    if n > 0:
        break

cents = int((n * 100) + 0.5)

coins = 0
for coin in [25, 10, 5, 1]:
    coins += cents // coin
    cents %= coin

print(coins)
