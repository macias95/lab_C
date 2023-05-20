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
    for(int i = 0;i<n;i++){
        *(p+i) = i_rand(-5, 5);
        printf("%d ",*(p+i)); 
    }
    int roz_n = 0, roz_p = 0;
    int *wsk_p = &roz_p;
    printf("\n____________________\n");

    p = realloc(p, 2*n*sizeof(int));
    for(int i =n; i<2*n;i++){
        p[i]=i_rand(-5, 5);
    }
    show_tab(p,2*n);
    free(p);



    }