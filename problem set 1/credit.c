#include <stdio.h>
#include <cs50.h>

long get_positive_long(string prompt);
bool checksum(long num_to_check);
void print_type(long credit_num);

int main(void)
{
    long number = get_positive_long("Type your credit card's number: "); //prompt for input
    bool is_valid = checksum(number);//calculate checksum and return true or false
    if (is_valid == 0 || number < 4000000000000 || number > 5599999999999999) //checks for ivalid length and numbers
    {
        printf("INVALID\n");
    }
    else
    {
        print_type(number); //length & starting digits for type
    }
}


long get_positive_long(string prompt)
{
    long positive_long;
    do
    {
        positive_long = get_long("%s", prompt);
    }
    while (positive_long < 0);
    return positive_long;
}

bool checksum(long num_to_check)
{
    long sum = 0;
    long step = 100;
    long copy = num_to_check;//initialize my variables
    do
    {
        if (((num_to_check % step) / (step / 10)) * 2 > 9) //check if the product has two digits
        {
            sum += (((num_to_check % step) / (step / 10)) * 2) % 10;
            sum += (((num_to_check % step) / (step / 10)) * 2) / 10;
        }
        else
        {
            sum += ((num_to_check % step) / (step / 10)) * 2 ;
        }
        copy /= 100; //copy of the number to check the digits
        step *= 100; //proceeds two digits to the left
    }
    while (copy > 0); //checks if we are out of digits
    step = 10;
    copy = num_to_check;//re-initialize step to find the last digit and my copy
    do
    {
        sum += ((num_to_check % step) / (step / 10));
        copy /= 100;
        step *= 100;
    }
    while (copy > 0);
    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print_type(long credit_num)
{
    if (credit_num > 999999999999999) //16 digits
    {
        if (credit_num / 100000000000000 > 50 &&  credit_num / 100000000000000 < 56)
        {
            printf("MASTERCARD\n");
        }
        else if (credit_num / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (credit_num > 99999999999999)//15 digits
    {
        if (credit_num / 10000000000000 == 34 ||  credit_num / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        else if (credit_num / 100000000000000 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (credit_num / 1000000000000 == 4)//13 - 14 digits
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
