#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Gets name and displays it to console
    string name = get_string("What's your name?\n");
    printf("Hello, %s\n", name);
}
