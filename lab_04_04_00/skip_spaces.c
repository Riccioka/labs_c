char *skip_spaces(char *str)
{
    while (*str == ' ' || *str == '\t')
        ++str;
    return str;
}
