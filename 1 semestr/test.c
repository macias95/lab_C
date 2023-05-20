#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 8



void U2(int p){
    char tab[N+1];
    tab[8] = '\0';
    if((p>127) || (p<-128)){
        printf("Liczba %d jest poza zakresem\n", p);
        return;
    }
    else{
        if(p>=0){
         tab[0] ='0';
         int k;
         k = p;
         for(int i=7;i>1; --i){
           if((k % 2)==1)
                tab[i]='1';
            else
                tab[i]='0';
            k =(k/2);
         }
        }
        else{
            tab[0]='1';
            int r =1, k;
            k = p;
            for(int i = 0; i<7;++i){
                r=r*2;
            }
            k = r-p;
            for(int i=7;i>1; --i){
            if((k % 2)==1)
                tab[i]='1';
            else
                tab[i]='0';
            
            k = (k/2);
        }
    }
   }
   printf("%4d = %s\n", p, tab);
} 


int main(void){
    U2(-25);
}