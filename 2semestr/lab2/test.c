#include<stdio.h>
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i >> 1)
        (n & i) ? printf("1") : printf("0");
}
 
int main(void)
{
    unsigned mask = 1;
    for(int i = 0; i<10; i++){
        mask=(mask<<1);
        mask+=1;
    }
    bin(~mask);
    printf("\n");
    bin(4);
}
