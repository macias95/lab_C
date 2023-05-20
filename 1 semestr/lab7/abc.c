#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    char tab[9] = "zbc def";
    int k = 9;
    char *w = tab;
    if(isalpha(tab[0])==2){
        tab[0]+=10;
        if(isalpha(tab[0])==0){
            tab[0]-=26;
        }
    }
    printf("%c", tab[0]); 
}

