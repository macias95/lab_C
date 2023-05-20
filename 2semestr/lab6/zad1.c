#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void){
    srand(time(0));
    int rows = 3 + rand()%4;//ilosc wierszy
    int columns = 3 + rand()%4;//ilosc kolumn, czyli dlugosc wiersza

    int **array_1 = malloc (rows * sizeof(int*));
    for (int i = 0; i < rows; i++){
        array_1[i] = malloc (columns * sizeof(int)); //alokacja wiersza
    for (int j = 0; j < columns; j++)
        array_1[i][j] = 1 + rand()%15; //wypelnienie wiersza wartosciami
    }

    int **array_2 = malloc (rows * sizeof(int*));
    array_2[0] = malloc (columns * rows * sizeof(int)); //alokacja wierszy
    for (int j = 0; j < rows * columns; j++)
        array_2[0][j] = 1 + rand()%15; //wypelnienie wierszy wartosciami
    for (int i = 1; i < rows; i++){
        array_2[i] = array_2[i-1] + columns;
    }

    //wypisywanie pierwszej tablicy
    printf("%d   %d\n", rows, columns);
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d, ", array_1[i][j]);
        }
        printf("\n");
    }
    printf("tab2\n");
     for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d, ", array_2[i][j]);
        }
        printf("\n");
    }

    //losowanie nowych wartości tablicy
    int rows_new = 3+rand()%8;
    printf("\n\n rows_new = %d\n", rows_new);
    if(rows_new>rows){
        array_1 = realloc(array_1, rows_new*sizeof(int*));
        for(int i=rows;i<rows_new;i++){
            array_1[i] = malloc (columns * sizeof(int)); //alokacja wiersza
            for(int j=0;j<columns;j++){
                array_1[i][j] = (-15) + rand()%15; //wypelnienie wiersza wartosciami
            }
        }
    }
    if(rows_new<rows){
        for(int i=rows_new;i<rows;i++){
            free(array_1[i]);
        }
    }
    for(int i=0;i<rows_new;i++){
        for(int j=0;j<columns;j++){
            printf("%d, ", array_1[i][j]);
        }
        printf("\n");
    }
    

    free(array_1);
    free(array_2);

}