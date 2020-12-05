#include <stdio.h>
#include <cs50.h>

int get_int_in_range(string prompt, int min, int max);
void build_pyramid(int height);

int main(void)
{
    int height = get_int_in_range("Give me the pyramids height (1 - 8): ", 1, 8); //ask pyramids size
    build_pyramid(height); //build pyramid

}

int get_int_in_range(string prompt, int min, int max)
{
    int number; //creating an int variable
    do
    {
        number = get_int("%s", prompt); //Prompting user to set the number
    }
    while (number < min || number > max); //Check if the number is in range
    return number;
}

void build_pyramid(int size)
{
    for (int height = 0; height < size; height++)
    {
        for (int space = size - height - 2; space >= 0; space--) //creating the empty space
        {
            printf(" ");
        }
        for (int left = 0; left <= height; left++) //creating the left pyramid's side
        {
            printf("#");
        }
        printf("  ");//creating the gap between sides
        for (int right = 0; right <= height; right++) //creating the right pyramid's side
        {
            printf("#");
        }
        printf("\n");
    }
}
