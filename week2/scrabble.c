#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int get_score(string s);

int main(void)
{
    // Prompt the user for two words
    string u1 = get_string("Player1 :");
    string u2 = get_string("Player2 :");
    // Compute the score of each word
    int score1 = get_score(u1);
    int score2 = get_score(u2);
    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_score(string s)
{
    // 给总分数附初始值
    int sum = 0;

    // 计算每个字符的分数
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isupper(s[i]))
        {
            sum += scores[s[i] - 'A'];
        }
        else if (islower(s[i]))
        {
            sum += scores[s[i] - 'a'];
        }
    }

    return sum;
}
