char* my_strpbrk(const char *str1, const char *str2)
{
    char *str2_safe;

    while (*str1)
    {
        str2_safe = (char*)str2;
        while (*str2_safe)
        {
            if (*str1 == *str2_safe)
                return (char*)str1;
            str2_safe++;
        }
        str1++;
    }
    return 0;
//    return (void*)0;
}
