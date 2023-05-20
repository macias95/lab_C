#include<stdio.h>

void write_binar(unsigned n, char* wsk){
    while(n>=1){
        if(n%2==0){
            *wsk = '0';
            n=n/2;
        }
        else{
            *wsk = '1';
            n=(n-1)/2;
        }
        wsk--;
    }
}

void write_tab(char *wsk){
    for(int i = 0; i<30; i++){
        printf("%c", *(wsk+i));
    }
}

unsigned bits(unsigned x, unsigned n){
    unsigned mask = 1;
    for(int i=0;i<x;i++){
        mask=(mask<<1);
        mask+=1;
    }
    n = n&(~mask);
    return n;


}

void main(void){
    char tab[32];
    char tab1[32];
    unsigned int l;
    for(int i = 0; i<30; i++){
        tab[i] = '0';
        tab1[i] = '0';
    }
    printf("Podaj liczbę do zamiany: ");
    scanf("%d",&l);
    write_binar(l,tab+30);
    printf("%s\n",tab);
    unsigned n = bits(30, l);
    write_binar(n, tab1+30);
    printf("%s", tab);
     


}