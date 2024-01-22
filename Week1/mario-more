#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //获取高度
    int h = 0;
    do
    {
        h = get_int("Height:");
    }
    while (h < 1 || h > 8);

    //拙劣的输出
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h - i - 1; j++)
        {
            printf(" ");
        }
        for (int m = 0; m < i + 1; m++)
        {
            printf("#");
        }
        printf("  ");
        for (int n = 0; n < i + 1; n++)
        {
            printf("#");
        }
        printf("\n");
    }
}
