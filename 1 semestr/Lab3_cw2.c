#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i_rand(int min, int max){
return rand() % (max-min+1) + min;
}

int main(void){
    srand(time(0));
    int a, b;
    int tab[10];
    for(int i = 0; i < 10; ++i)
    {
        a = i_rand(-10, 10);
        tab[i] = a;
    }

    for(int i = 0; i < 10; ++i)
    {
        printf("tab[%d] = %d \n", i, tab[i]);
    }
    printf("\n");

    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j< 9-i; ++j)
        {
            if(tab[j] > tab[j+1]) 
            {
                b = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = b;
            }
        }
    }

    for(int i = 0; i < 10; ++i)
    {
        printf("tab[%d] = %d \n", i, tab[i]);
    }
    return 0;
}