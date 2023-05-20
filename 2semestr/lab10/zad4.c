#include<stdio.h>
#include<stdlib.h>

int suma (int *p, int len) {
int sum = 0;
for (int i = 0; i < len; i++)
sum += p[i];
return sum;}

int var_cmp_pnt(const void* a, const void* b) {
    const int *var = a;
    const int * const * bv = b;
    return *var - suma(*bv, 10);
    
}
  
int var_cmp(const void* a, const void* b) {
    const int *var = a;
    const int *bv = b;
    return *var - suma(bv, 10);
    
}

int cmp_i(const void *a,const void*b){
    return *(const int *)a - *(const int*)b;
}

//generowanie liczb losowych calkowitych z przedziału (min, max)
int i_rand(int min, int max){
return rand() % (max-min+1) + min;
}
//generowanie liczb losowych rzeczywistych z przedziału (min, max)
double d_rand(double min, double max){
double r = (double) rand()/RAND_MAX;
return r*(max-min) + min;
}
void wypisz_i (int *poczatek, int *koniec) {
while (poczatek < koniec)
printf ("%4d ", *poczatek++);
printf ("\n");
return;}

void print_tab_all(int y,int a[][y], int x){
int i, j;
for (i = 0; i < x; i++){
for (j = 0; j < y; j++)
printf ("%3d", a[i][j]);
printf ("\n"); }
return;}

int main() {
    int **tab_3 = malloc( 15*sizeof(int*));
    for(int i = 0; i < 15; i++) tab_3[i] = malloc(10 * sizeof(int));
    for(int i = 0; i < 15; i++) for(int j = 0; j < 10; j++) tab_3[i][j]  =  rand() % 21;
    
    for(int i = 0;i<15;i++){
        qsort(tab_3[i], 10, sizeof(int), cmp_i);
    }
    for(int i=0;i<15;i++){
        wypisz_i(tab_3[i], tab_3[i]+10);
    }
    
    int **tab_33 = malloc( 15 * sizeof(int*));
    int *tab_33_org = tab_33[0] = malloc(10 * 15 * sizeof(int));
    for(int i = 1; i < 15; i++) tab_33[i] = tab_33[i-1] + 10 ;
    for(int i = 0; i < 15; i++) for(int j = 0; j < 10; j++) tab_33[i][j]  =  rand() % 21;
    printf("\n");
    for(int i = 0;i<15;i++){
        qsort(tab_33[i],10,sizeof(int),cmp_i);
        wypisz_i(tab_33[i],tab_33[i]+10);
    }
    int (*tab_333)[10] = malloc(10 * 15 * sizeof(int));
    for(int i = 0; i < 15  ; i++) for(int j = 0; j < 10; j++) tab_333[i][j]  =  rand() % 21;
    // ...
    int var = 13;
    int **w1 = bsearch(&var, tab_3, 15, sizeof(int*), var_cmp_pnt);
    int **w2 = bsearch(&var, tab_33, 15, sizeof(int*), var_cmp_pnt);
    int (*w3)[10] = bsearch(&var, tab_333, 15, 10*sizeof(int), var_cmp);
    if(w1 != NULL) { printf("tab_3: %d\n", w1-tab_3); wypisz_i(*w1, *w1+10); } else printf("Nie istnieje.\n");
    if(w2 != NULL) { printf("tab_33: %d\n", w2-tab_33); wypisz_i(*w2, *w2+10); } else printf("Nie istnieje.\n");
    if(w3 != NULL) { printf("tab_333: %d\n", w3-tab_333); wypisz_i(*w3, *w3+10); } else printf("Nie istnieje.\n");
}
