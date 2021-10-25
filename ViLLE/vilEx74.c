int count_args(int *ipn, ...)
{
        int cnt = 0;
        char *pnt;
        *ipn = 0;
        va_list argptr;
        va_start(argptr, ipn);
        do{
            pnt = va_arg(argptr, const char*);
            if(pnt != NULL) {
                cnt++;
                *ipn += strlen(pnt);
            }
        }while(pnt != NULL);

        va_end(argptr);
    return cnt;
}