#include<stdio.h>
#include<stdlib.h>

void wypisz_f (float *poczatek, float *koniec) {
while (poczatek < koniec)
printf ("%6.2f", *poczatek++);
printf ("\n");
return;}

int main(void){
    float tab_2[7] = {1,2,3,4,5,6,9};
    float *tab_1[7], **wsk, *wsk_1;
    for(int i =0;i<7;i++){
        tab_1[i]=tab_2+i;
    }
    wsk = tab_1;

    for(int i =0;i<7;i++){
        printf("%p\t%p\n", tab_1[i], tab_2[i] );
    }
    printf("\n");
    for(int i =0;i<7;i++){
        printf("%p\n", *(wsk+i));
    }

    




}