# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
int letters;
int sentences;
int words;
int grade;
float L;
float S;

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);


int main(void)
{

    string text_input = get_string("Text: ");
    letters = count_letters(text_input);
    words = count_words(text_input);
    sentences = count_sentences(text_input);
    // L is the average number of letters per 100 words
    L = ((float)letters / words) * 100;
    S = ((float)sentences / words) * 100;

    grade = round((0.0588 * L) - (0.296 * S) - 15.8);

    printf("The grade is .. %i\n", grade);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}

int count_letters(string text)
{

    int count = 0;
    for (int i = 0; i < strlen(text); i ++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            count ++;
        }
    }
    return count;
}

int count_words(string text)
{

    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];
        if (c == ' ')
        {
            count ++;
        }
    }
    return count + 1;
}

int count_sentences(string text)
{

    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];
        if (c == '.' || c == '?' || c == '!')
        {
            count ++;
        }
    }
    return count;
}