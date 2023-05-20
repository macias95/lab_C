#include <stdio.h>

void neguj(int* a ,int p){
    int mask, results;
    mask = (1<<(p-1));
    results =*a & mask;
    printf("Results %d, maska: %d", results, mask);

}

int main(void){
    int a, p;
    printf("Podaj liczbę: ");
    scanf("%d",&a);
    printf("\nPodaj bit, który chcesz zanegować: ");
    scanf("%d",&p);
    neguj(&a, p);
    return 0;
}
