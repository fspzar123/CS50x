from cs50 import get_int

# Get input from the user
while True:
    n = get_int("Height of the pyramid: ")
    if n > 0 and n < 9:
        break

# Prints the pyrmaid after getting input
height = n
for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i)