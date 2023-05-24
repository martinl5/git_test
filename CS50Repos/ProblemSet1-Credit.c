#include <cs50.h>
#include <stdio.h>

int get_length(long number);
bool check_valid(long number);

int main(void)
{
    long number = get_long("Number: ");
    int length = get_length(number);


    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    if (!check_valid(number))
    {
        printf("INVALID/n");
        return 0;
    }

    long start = number;
    do
    {
        start = start / 10;
    }
    while (start > 100);

    //American Express Check
    if(length == 15 && (start==34 || start==37))
    {
        printf("AMERICAN\n");
    }
    else if(length == 16 && (start >= 51 && start <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if((length == 13 || length == 16) && start/10 == 4)
    {
        printf("VISA\n");
    }
}

int get_length(long number)
{
    int ans = 0;
    while (number > 0)
    {
        number = number / 10;
        ans++;
    }
    return ans;
}

bool check_valid(long number)
{
    int sum1 =0;
    int sum2 =0;
    int num1;
    int num2;
    int digit1;
    int digit2;
    do
    {
        num1 = number%10;
        sum1 += num1;
        number = number/10;

        num2 = number%10;
        number = number/10;

        num2 = num2*2;
        digit1 = num2%10;
        digit2 = num2/10;

        sum2 = sum2 + digit1 + digit2;
    } while(number > 0);
    int total = sum1 + sum2;
    if(total%10 == 0)
    {
        return true;
    }
    return false;
}