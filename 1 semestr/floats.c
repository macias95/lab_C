#include <stdio.h>
#include <math.h>

int main(void){
   int i;
   int j;
   printf("Podaj liczbę\t");
   scanf("%d",&j);
   for(i = 1; i < j ; i++, j -=2){
    printf("a = %d, a b = %d \n",i, j);
   }

    return 0;
}