#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


char eng[12][12]= {"January","February","March","April","May","June","July","August","September","October","November","December"};
char ita[12][12]= {"Gennaio","Febbraio","Marzo","Aprile","Maggio","Giugno","Luglio","Agosto","Settembre","Ottobre","Novembre","Dicembre"};
char spa[12][12]= {"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"};

typedef enum { English, Italian, Spanish } language;
const char *month(int number, language lang);
const char *lang2str(language lang);

int main(void)
{
    printf("%s\n", month(2, Italian));
    return 0;
}


const char *month(int number, language lang)
{
    for(int i = 1; i<=12; i++)
    {
        if(number == i) {
            if (lang == English) return eng[i-1];
            else if (lang == Italian) return ita[i-1];
            else if (lang == Spanish) return spa[i-1];
            else return "Error";
        }

    }
    return "Error";
}
const char *lang2str(language lang)
{
    if(lang == English) return "English";
    else if(lang == Italian) return "Italian";
    else if(lang == Spanish) return "Spanish";
    else return "Error";
}