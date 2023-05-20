#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

char *zmienna_liczba_parametrow(char *pierwszy, ...)
{
    va_list argumenty;
    va_start(argumenty, pierwszy);

    int dlugosc = strlen(pierwszy);
    char *parametr;

    while ((parametr = va_arg(argumenty, char *)) != NULL)
    {
        dlugosc += strlen(parametr);
    }

    char *wynik = malloc((dlugosc + 1) * sizeof(char));
    strcpy(wynik, pierwszy);

    va_end(argumenty);

    va_start(argumenty, pierwszy);

    while ((parametr = va_arg(argumenty, char *)) != NULL)
    {
        strcat(wynik, parametr);
    }

    va_end(argumenty);

    return wynik;
}

int main()
{
    char *wynik = zmienna_liczba_parametrow("If you. ", "cos", " cos", NULL);
    printf("Wynik: %s\n", wynik);
    free(wynik);
    return 0;
}
