from cs50 import get_string

# Coleman-Liau index is computed as 0.0588 * L - 0.296 * S - 15.8,
# where L is the average number of letters per 100 words in the text,
# and S is the average number of sentences per 100 words in the text.

end_of_sentence = ["?", "!", "."]

s = get_string("Text: ")

number_of_sentences = 0
number_of_words = 0
number_of_letters = 0

for char in s:
    if char in end_of_sentence:
        number_of_sentences += 1

for char in s:
    if char.isalnum():
        number_of_letters += 1

# split to list and get the number of elements in list
number_of_words = len(s.split())


per_100_words = number_of_words / 100
L = number_of_letters/per_100_words
S = number_of_sentences/per_100_words
grade = int(round(0.0588 * L - 0.296 * S - 15.8))

if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")