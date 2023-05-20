#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int i_rand(int min, int max){
return rand() % (max-min+1) + min;}

void show_tab(int *a, int n){
    for(int i=0;i<n;i++){
        printf("%d  ", *(a+i));
    }
}

int main(void){
    int *p, *arg_p, *arg_n;
    int n;
    srand(time(0));
    printf("podaj rozmian tablicy: ");
    scanf("%d", &n);
    printf("\n");
    p = malloc(n*sizeof(int));
    arg_n = malloc(sizeof(int));
    arg_p = malloc(sizeof(int));
    for(int i = 0;i<n;i++){
        *(p+i) = i_rand(-5, 5);
        printf("%d ",*(p+i)); 
    }
    int roz_n = 0, roz_p = 0;
    printf("\n");
    for(int i = 0; i<n; i++){
        if(*(p+i)%2==0){
            roz_p++;
            arg_p = realloc(arg_p,roz_p*sizeof(int));
            *(arg_p+roz_p-1) = *(p+i);
        }
        else{
            roz_n++;
            arg_n = realloc(arg_n,roz_n*sizeof(int));
            *(arg_n+roz_n-1) = *(p+i);
        }
    }
    
   

    
    printf("\n");
    printf("\n");
    printf("rozmiar arg_p: %d\n",roz_p);
    printf("arg_p: ");
    show_tab(arg_p,roz_p);
    free(arg_n);
    free(arg_p);
    free(p);
}
