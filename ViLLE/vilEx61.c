
int digit_counter(unsigned int nr)
{
    int count = 0;
    while(read_line(char *line, 10))
    {
        ret = strstr(line, "0b");
        while(*(ret+2) == 0 || *(ret+2) == 1) {
            while(binary_reader(nr)) count++;
        }
    }
    return count;
}

bool binary_reader(unsigned int *pu)
{
      if ( *pu & 01) {
         *pu <<=1;
         *pu+=0;
         return true;
      }
    else return false;
}