int filter_alpha(char * str, int size, char (*my_getchar)(void))
{
    int i = 0; int count = 0;
    char c = 'a';
    do {
        c = my_getchar();
        if(c != '\0') count ++;
        if(c != '\n' && c != '\0' && i < size && c != ' ' && isalpha(c)) {
            str[i] = c;
            i++;
        }
    } while(c != '\n' && c != '\0' &&  i < size-1);
    str[i] = '\0';
    return count;
}