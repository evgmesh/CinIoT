void *pn_fun(char ch)
{
    printf("%c", ch);
}

int print_string(char * str, void *pn_fun(char ch))
{
    int size = 0;
    size = strlen(str);
    for(int i = 0; i<size; i++) pn_fun(str[i]);
    return size;
}
