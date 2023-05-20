#include<stdio.h>

void main(void){
    unsigned int i = 25; 
    int licznik = 0;
    while(i>0){
        if(i&1==1){
        licznik+=1;
        }
        i=i>>1;
    }
   
    printf("Liczba 1: %d", licznik);

}