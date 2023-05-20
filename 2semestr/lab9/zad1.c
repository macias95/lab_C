#include<stdio.h>
#include<stdlib.h>
int s;
int suma (int *tab, int len) {
int ss = 0;
for (int i = 0; i < len; i++)
ss+= tab[i];
return ss;}

void print_tab_all(int y,int a[][y], int x){
int i, j;
for (i = 0; i < x; i++){
for (j = 0; j < y; j++)
printf ("%3d", a[i][j]);
printf ("\n"); }
return;}

int cmp_1(const void *a, const void *b){
    return *(const int*)a - *(const int*)b;
}

int cmp_2(const void *a, const void *b){
    int ap = suma((int*)a, s);
    int bp = suma((int*)b,s);
    return(ap-bp);
}

void proc_1(int col, int(*tab)[col], int n){
    s = col;
    for(int i=0;i<n;i++){
        qsort(tab+i,col, sizeof(int), cmp_1);
    }
}
void proc_2(int col, int (*tab)[col], int n){
    qsort(tab, n, sizeof(int)*col, cmp_2);
}



int main(void){
    int tab_A[3][6]={{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    int tab_B[4][3]={1,-24,1,9,32,2,5,64,1,3,32,1};
    print_tab_all(3, tab_B, 4);
    printf("\n");
    proc_1(3, tab_B, 4);
    print_tab_all(3, tab_B, 4);
    printf("\n");
    proc_2(3, tab_B, 4);
    print_tab_all(3, tab_B, 4);


}