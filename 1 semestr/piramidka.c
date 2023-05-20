#include<stdio.h>
 int main(void){
    int rows;
    int i, j, k=0;
    printf("Podaj ilość wierszy ");
    scanf("%d", &rows);
    
    for(i=1;i<=rows;++i, k = 0){
        for(j=1;j<=rows-i;++j){
            printf(" ");
        }
        while(k!= 2*i-1){
            printf("%d", rows);
            k++;
        }
        printf("\n");
    }
    return 0;
 }