#include "helpers.h"
#include <stdio.h>
#include <math.h>

void sideAvg(int side, int height, int width, RGBTRIPLE image[height][width]);
void cornerAvg(int which, int height, int width, RGBTRIPLE image[height][width]);
int averageRed, averageBlue, averageGreen;
// RGBTRIPLE -- > The hight and width of the pixel. image[0] - > the first row. Lastrow = image[height-1].
// A particular pixel = image[0][0] first pixel, image[2][3] = row 3 column4


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop through the array twice to access all pixels and modify them
    for (int row = 0; row < height ; row++)
    {
        for (int col = 0; col < width ; col++)
        {
            // find average
            int avg = round((image[row][col].rgbtBlue + image[row][col].rgbtRed + image[row][col].rgbtGreen) / 3.0);
            // apply the averages
            image[row][col].rgbtBlue = avg;
            image[row][col].rgbtRed = avg;
            image[row][col].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // loop through the array twice to access all pixels and modify them
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width ; col++)
        {
            int sepiaRed = round(0.393 * image[row][col].rgbtRed + 0.769 * image[row][col].rgbtGreen + 0.189 * image[row][col].rgbtBlue);
            int sepiaGreen = round(0.349 * image[row][col].rgbtRed + 0.686 * image[row][col].rgbtGreen + 0.168 * image[row][col].rgbtBlue);
            int sepiaBlue = round(0.272 * image[row][col].rgbtRed + 0.534 * image[row][col].rgbtGreen + 0.131 * image[row][col].rgbtBlue);

            // check if its greater than 255
            if ( sepiaRed >= 255) sepiaRed = 255;
            if ( sepiaBlue >= 255) sepiaBlue = 255;
            if ( sepiaGreen >= 255) sepiaGreen = 255;

            image[row][col].rgbtRed = (int) sepiaRed;
            image[row][col].rgbtGreen = (int) sepiaGreen;
            image[row][col].rgbtBlue = (int) sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int actual_width = width -1;
    int rgbtRedtemp;
    int rgbtBluetemp;
    int rgbtGreentemp;
    // loop through the array twice to access all pixels and modify them
    for (int row = 0; row < height; row++)
    {
        // check width column wheter its odd or even
        int tmp_width = actual_width;

        if ((width % 2) != 0) //odd
        {
            for (int col = 0; col < round((width) / 2); col++)
            {
                rgbtRedtemp = image[row][col].rgbtRed;
                rgbtBluetemp = image[row][col].rgbtBlue;
                rgbtGreentemp = image[row][col].rgbtGreen;

                image[row][col].rgbtRed = image[row][tmp_width].rgbtRed;
                image[row][col].rgbtGreen =  image[row][tmp_width].rgbtGreen;
                image[row][col].rgbtBlue = image[row][tmp_width].rgbtBlue;

                image[row][tmp_width].rgbtRed = rgbtRedtemp;
                image[row][tmp_width].rgbtBlue = rgbtBluetemp;
                image[row][tmp_width].rgbtGreen = rgbtGreentemp;

                tmp_width --;
            }
        }
        else //even
        {
            for (int col = 0; col < round((width) / 2); col++)
            {
                rgbtRedtemp = image[row][col].rgbtRed;
                rgbtBluetemp = image[row][col].rgbtBlue;
                rgbtGreentemp = image[row][col].rgbtGreen;

                image[row][col].rgbtRed = image[row][tmp_width].rgbtRed;
                image[row][col].rgbtGreen =  image[row][tmp_width].rgbtGreen;
                image[row][col].rgbtBlue = image[row][tmp_width].rgbtBlue;

                image[row][tmp_width].rgbtRed = rgbtRedtemp;
                image[row][tmp_width].rgbtBlue = rgbtBluetemp;
                image[row][tmp_width].rgbtGreen = rgbtGreentemp;

                tmp_width --;
            }
        }

    }
    return;
}

struct coordinate{
    int x;
    int y;
};

struct a_box{
    struct coordinate coordinates[9];
};

// make a box coordinate
struct a_box box;

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    for each row
    for each col
        set count to 0
        for every neighbouring pixel within the radius m in the x direction
            for every neighbouring pixel within the radius m in the y direction
                add the colour to the total
                count++
        final_colour = total / count
        setpixel (current x, currenty,final_colour)
    */
    RGBTRIPLE temp[height][width];

    for ( int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int count = 0;
            int rowCoords[] = {row - 1,row,row + 1};
            int colCoords[] = {col - 1,col,col + 1};
            float totalRed = 0, totalGreen = 0, totalBlue = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int curRow = rowCoords[r];
                    int curCol = colCoords[c];
                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width)
                    {
                        RGBTRIPLE pixel = image[curRow][curCol];

                        totalRed +=  pixel.rgbtRed;
                        totalGreen += pixel.rgbtGreen;
                        totalBlue += pixel.rgbtBlue;
                        count ++;
                    }
                }
            }
            temp[row][col].rgbtRed = round(totalRed/count);
            temp[row][col].rgbtGreen = round(totalGreen/count);
            temp[row][col].rgbtBlue = round(totalBlue/count);
        }

    }

    // put into actual image
    for ( int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
