# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

bool check_int(string input);
string encipher(string text, int key);

int main(int argc, string argv[])
{
    // Check if correct number of arguments and type is correct
    string input = argv[1];

    if (argc != 2 || !check_int(input))
    {
        printf("Usage: ./caesar key\n");
        return true;
    }

    int key = atoi(input);
    string s = get_string("plaintext: ");
    string output = encipher(s, key);
    printf("ciphertext: %s\n", output);
}

bool check_int(string input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        char c = input[i];
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

string encipher(string text, int key)
{
    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];
        int index = 0;
        // Check if upper or is lower
        if (islower(c))
        {
            // lower case
            index = c - 97;
            // apply formula
            char cipher_c = (index + key) % 26;
            cipher_c += 97;
            text[i] = cipher_c;
        }
        else if (isupper(c))
        {
            // Upper case
            index = c - 65;
            char cipher_c = (index + key) % 26;
            // reverse the alphabet
            cipher_c += 65;
            // replace each text
            text[i] = cipher_c;
        }
        else
        {
            char cipher_c = c ;
            text[i] = cipher_c;
        }
    }
    return text;
}