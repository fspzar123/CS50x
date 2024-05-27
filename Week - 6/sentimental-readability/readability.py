from cs50 import get_string
import math

# Get the text from the user
text = get_string("Text: ")
letters = float(0)
words = float(1)
sentences = float(0)

# Converting text to integer
n = len(text)

# counting the number of letters
for i in range(n):
    if (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z'):
        letters += 1

# counting the number of words
for i in range(n):
    if text[i].isspace():
        words += 1

# counting the number of sentences
for i in range(n):
    if text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences += 1
        
# Calculating the index of grade
l = 100 * letters/words
s = sentences/words * 100
index = round(0.0588 * l - 0.296 * s - 15.8)
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")
