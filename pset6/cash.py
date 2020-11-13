from cs50 import get_float

total_coins = 0

# Locate the index to perform integer division from the coins list
coins = [1, 5, 10, 25]

while True:
    cash = get_float("Change owed: ")
    if cash > 0:
        break

cents = cash * 100

# Reiterate backwards the index of coins
idx = len(coins) - 1

while idx >= 0:
    # perform integer division if the cents are bigger than the coins
    if coins[idx] <= cents:
        number_of_coins = int(cents/coins[idx])
        total_coins += number_of_coins
        cents -= number_of_coins * coins[idx]
    idx -= 1

print(total_coins)
