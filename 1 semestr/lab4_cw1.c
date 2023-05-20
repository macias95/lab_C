#include <stdio.h>

int funkcja(int i){
    return (i + 1);
}

int main(void){
    int j;
    printf("Ile razy funkcja f3 ma się wywołać:  ");
    scanf("%d", &j);
    for(int i; i < j; i++)
    {
        printf("Funkcja wywołanie %d\n", funkcja(i));
    }
    return 0;
}