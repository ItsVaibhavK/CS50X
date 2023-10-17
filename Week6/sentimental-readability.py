# index = 0.0588 * L - 0.296 * S - 15.8
# L is the average number of letters per 100 words in the text
# S is the average number of sentences per 100 words in the text

from cs50 import get_string

# user input, use strip to get accurate number of spaces to help calculate number of words
text = get_string("Text: ").strip()

# length of text
length = len(text)

# count the number of letters, words, and sentences in the text
letters = 0
for i in range(length):
    if text[i].isalnum():
        letters += 1

# number of spaces in a sentence is 1 < number of words, so start counter at 1 to compensate
words = 1
for i in range(length):
    if text[i].isspace():
        words += 1

sentences = 0
for i in range(length):
    if text[i] == '!' or text[i] == '?' or text[i] == '.':
        sentences += 1

# calculate index
index = (0.0588 * ((letters / words) * 100)) - (0.296 * ((sentences / words) * 100)) - 15.8
grade = round(index)

# print result
if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")