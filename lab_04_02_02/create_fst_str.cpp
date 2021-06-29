int create_fst_str(char fst_str[][17], char *lens_str, char *res)
{
    char *words = NULL;
    int len = 0, i = 0, len_fst = 0;

    while ((words = my_strtok(&res, ",;:-.!? ", &len)))
    {
        if (!len)
            continue;

        char word[len + 1];

        for (i = 0; i != len; i++)
            word[i] = words[i];
        word[i] = '\0';

        for (i = 0; i != len + 1; i++)
            fst_str[len_fst][i] = word[i];

        lens_str[len_fst] = len;
        len_fst++;
        remove_word_from_str(res, word, len);
    }
    return len_fst;
}
