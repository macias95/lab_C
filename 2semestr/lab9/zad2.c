#include<stdio.h>
#include<stdlib.h>

int cmp_1(const void *a, const void *b){
    return *(const int*)a - *(const int*)b;
}
void proc_1(int col, int(*tab)[col], int n){
    for(int i=0;i<n;i++){
        qsort((*tab)+i*col,col, sizeof(int), cmp_1);
    }
}

void serch_key(int c,int (*tab)[c],  int r, int* key){
    const int *a;
    for(int i=0;i<r;i++){
        a = bsearch(key, (*tab)+c*i, c, sizeof(int),cmp_1);
        if(a){
           wypisz_i((*tab)+i*c,(*tab)+i*c+c);
           return;
        }
    }
    if(a == NULL){
        printf("Brak podanej wartości w tablicy!!!");
    }
}

void wypisz_i (int *poczatek, int *koniec) {
while (poczatek < koniec)
printf ("%4d ", *poczatek++);
printf ("\n");
return;}

int main(void){
    int tab_A[3][6]={{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    proc_1(6,tab_A,3);
    int key = 1;
    serch_key(6,tab_A,3,&key);

}   