from cs50 import get_float
import numpy as np

# Get input from user
while True:
    dollars = get_float("Change owed: ")
    if dollars >= 0:
        break

# Dollars to cents
cents = dollars * 100
# Round cents to the 2nd decimal
cents = round(cents, 2)
# Array of values for quaters, dime, nickel, penny
denominators = np.array([25, 10, 5, 1])
# New variable to calculate number of coins
coins = 0
# Subtracting the cents by the array and increasing the number of coins
for i in range(len(denominators)):
    while cents >= denominators[i]:
        cents -= denominators[i]
        coins += 1
print("", coins)
