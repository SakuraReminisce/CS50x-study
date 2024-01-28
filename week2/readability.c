#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_num_letter(string t);
int get_num_word(string t);
int get_num_sentence(string t);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text:");
    // Count the number of letters, words, and sentences in the text
    int letter = get_num_letter(text);
    int word = get_num_word(text);
    int sentence = get_num_sentence(text);
    // Compute the Coleman-Liau index
    int index = round(0.0588 * (letter / (float) word * 100) - 0.296 * (sentence / (float) word * 100) - 15.8);
    // Print the grade level
    if (index >= 1 && index <= 16)
    {
        printf("Grade %d\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
}

// 获取字母数量
int get_num_letter(string t)
{
    int number = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (isupper(t[i]) || islower(t[i]))
        {
            number++;
        }
    }
    return number;
}

// 获取单词数量
int get_num_word(string t)
{
    int number = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (t[i] == ' ')
        {
            number++;
        }
    }
    return number + 1;
}

// 获取句子数量
int get_num_sentence(string t)
{
    int number = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (t[i] == '?' || t[i] == '.' || t[i] == '!')
        {
            number++;
        }
    }
    return number;
}
