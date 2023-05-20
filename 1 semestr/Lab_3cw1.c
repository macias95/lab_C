#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i_rand(int min, int max){
return rand() % (max-min+1) + min;
}
double d_rand(double min, double max){
double r = (double) rand()/RAND_MAX;
return r*(max-min) + min;
}

int main(void){
    int n;
    srand(time(0));
    double liczba, min = 0, max = 9.999;
    printf("Podaj liczbę losowań: ");
    scanf("%d", &n);
    int tab[10];
    for(int i = 0; i<10; ++i)
    { 
        tab[i] = 0;
    }
    for(int i=0; i < n; ++i)
    {
        liczba = d_rand(min, max);
        for(int j = 0; j < 10; ++j)
        {
            if(liczba >= j && liczba < (j+1))
            {
                tab[j] += 1;
            }
        }

    }
    for(int i = 0; i < 10; ++i )
    {
        printf("Przedzaił [%d, %d): %d \n", i, (i+1), tab[i]);
    }
    return 0;
}