#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double d_rand(double min, double max){
double r = (double) rand()/RAND_MAX;
return r*(max-min) + min;
}

int main(void){
    srand(time(0));
    double tab[10];
    double a;
    for(int i = 0; i < 10; ++i)
    {
        tab[i]=d_rand(-100.0, 100.0);
    }
    for(int i = 0; i < 10; ++i)
    {
        printf("A[%d] = \t %.2f \n", i, tab[i]);
    }
    printf("\n");

    for(int i = 0; i < 5; ++i)
    {
        a = tab[i];
        tab[i] = tab[9 - i];
        tab[9-i] = a;
    }

    for(int i = 0; i < 10; ++i)
    {
        printf("A[%d] = \t %.2f \n", i, tab[i]);
    }

    return 0;
}