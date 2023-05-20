#include<stdio.h>
#include<stdlib.h>
#define Columns 6

void print_tab_all(int y,int**a, int x){
int i, j;
for (i = 0; i < x; i++){
for (j = 0; j < y; j++)
printf ("%4d", a[i][j]);
printf ("\n"); }
return;}

int **new_tab(int *row){
    int rows=1;
    int zmienna=1;
    int **tab = malloc(rows*sizeof(int*));
    tab[0]=malloc(Columns*sizeof(int));
    for(int j=0;j<Columns;j++){
        tab[0][j]=0;
    }
    int z = 0;
    while(zmienna!=0){
        printf("Podaj zmienną: ");
        scanf("%d", &zmienna);
        tab[rows-1][z] = zmienna;
        z++;
        
        if(z>Columns){
            rows++;
            tab=realloc(tab, rows*sizeof(int*));
            tab[rows-1]=malloc(Columns*sizeof(int));
            for(int j=0;j<Columns;j++){
                tab[rows-1][j]=0;
                }
            z=0;
        }
    }
    *row = rows; 
    return tab;
}
int main(void){
    int rows = 1;
    int *wsk_rows = &rows;
    int **tab = new_tab(wsk_rows);

    print_tab_all(Columns, tab, rows);
    free(tab);

}