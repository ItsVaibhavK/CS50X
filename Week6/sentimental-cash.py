from cs50 import get_float
# get required input
while True:
    change = get_float("Change owed: ")
    if change >= 0:
        break
# since change owed is entered in decimal dollar format, convert it for calculation by 25, 10, 5, 1
change = round(change * 100)
# counter for number of coins
coins = 0

# calculate quarters, nickels, dimes, pennies
while change >= 25:
    change -= 25
    coins += 1

while change >= 10:
    change -= 10
    coins += 1

while change >= 5:
    change -= 5
    coins += 1

while change >= 1:
    change -= 1
    coins += 1

# print number of coins
print(f"{coins}")