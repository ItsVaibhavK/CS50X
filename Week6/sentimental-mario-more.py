# get user's first input
height = input("Height: ")
# infinite loop till conditions are met (is a number, is >=1, is <=8)
while True:
    # if-else for if input is a number
    if height.isnumeric():
        # if it is a number, convert to int and check range in another nested if-else
        height = int(height)
        if height < 1 or height > 8:
            height = input("Height: ")
        else:
            height = int(height)
            break
    else:
        height = input("Height: ")

# for loop for rows
for i in range(height):
    # for loop for spaces
    for j in range(height - i - 1):
        print(" ", end="")
    # for loop for hashes
    for k in range(i + 1):
        print("#", end="")
    # fixed spaces
    print("  ", end="")
    # for loop for 2nd pyramid hashes
    for k in range(i + 1):
        print("#", end="")
    # new line to end that row
    print()

