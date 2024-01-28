#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int status(int c, string v);
string declassify(string s, string key);

int main(int argc, string argv[])
{
    // 提取key
    string key = argv[1];
    // 分析状态
    switch (status(argc, key))
    {
        case 1:
            printf("Usage: ./substitution key\n");
            return 1;
            break;

        case 2:
            printf("Key must contain 26 characters.\n");
            return 1;
            break;

        case 3:
            printf("Key character must be unique.\n");
            return 1;
            break;

        default:
            break;
    }
    // 输入和输出
    string plaintext = get_string("plaintext: ");
    string ciphertext = declassify(plaintext, key);
    printf("ciphertext:%s\n", ciphertext);
    return 0;
}

int status(int c, string v)
{
    // 直接按回车的结果
    if (c != 2)
    {
        return 1;
    }
    // 包含非字母的结果
    for (int i = 0, n = strlen(v); i < n; i++)
    {
        if (isalpha(v[i]) == 0)
        {
            return 1;
        }
    }
    // 未满26个字符的结果
    if (strlen(v) != 26)
    {
        return 2;
    }
    // 有字母重复的结果
    for (int i = 0, n = strlen(v); i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] == v[j])
            {
                return 3;
            }
        }
    }
    // 正常运行的结果
    return 0;
}

string declassify(string s, string key)
{
    string ciphertext = s;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isupper(s[i]))
        {
            ciphertext[i] = toupper(key[s[i] - 'A']);
        }
        else if (islower(s[i]))
        {
            ciphertext[i] = tolower(key[s[i] - 'a']);
        }
    }
    return ciphertext;
}
