#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num;
    //获取有效数字
    do
    {
        num = get_long("Number: ");
    }
    while (num <= 0);

    //验证卡号是否正确
    int checksum = 0;
    long checknum = num / 10;
    while (checknum > 0)
    {
        int remainder = checknum % 10 * 2;
        if (remainder < 10)
        {
            checksum += remainder;
        }
        else
        {
            checksum += remainder % 10;
            remainder /= 10;
            checksum += remainder;
        }
        checknum /= 100;
    }

    checknum = num;
    while (checknum > 0)
    {
        checksum += checknum % 10;
        checknum /= 100;
    }

    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        //获取长度
        int len = 2;
        while (num >= 100)
        {
            num /= 10;
            len++;
        }

        if ((num == 34 || num == 37) && len == 15)
        {
            printf("AMEX\n");
        }
        else if (num >= 51 && num <= 55 && len == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (num >= 40 && num <= 49 && (len == 13 || len == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
