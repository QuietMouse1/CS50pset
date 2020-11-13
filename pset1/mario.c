# include <stdio.h>
# include <cs50.h>

int main(void)
{
    int height = get_int("Height: ");
    while (true)
    {
        if (height >= 1 && height <= 8)
        {
            break;
        }
        else
        {
            height = get_int("Height: ");
        }

    }


    int hash_count = 0;
    int space_count = height;
    // Goes to every line
    for (int i = 0; i < height; i++)
    {
        hash_count += 1;
        space_count -= 1;
        //every line does what ?

        for (int z = 0; z < space_count; z++)
        {
            printf(" ");
        }

        for (int k = 0; k < hash_count; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
