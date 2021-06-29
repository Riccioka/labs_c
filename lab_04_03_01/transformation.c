#include <string.h>

int transformation(int len, char words[][17], char len_words[256], char new_str[256])
{
    int flag = 1, symbol[17], len_new = 0;

    for (int i = len - 2; i != -1; i--)
    {
        if (strcmp(words[i], words[len - 1]))
        {
            for (int j = 0; j != len_words[i]; j++)
            {
                char *index = strchr(words[i], words[i][j]);
                symbol[j] = *index;
                for (int k = 0; k != j; k++)
                    if (symbol[k] == symbol[j])
                        flag = 0;
                if (flag)
                {
                    new_str[len_new] = words[i][j];
                    len_new++;
                }
                flag = 1;
            }
            new_str[len_new] = ' ';
            len_new++;
        }
    }
    return len_new;
}
