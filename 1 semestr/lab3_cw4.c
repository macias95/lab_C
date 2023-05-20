#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i_rand(int min, int max){
return rand() % (max-min+1) + min;
}


int main(void){
    int A[50], B[50], C[51];
    
    srand(time(0));
    A[0] = i_rand(1, 9);
    B[0] = i_rand(1, 9);
    for(int i = 1; i < 50; ++i)
    {
        A[i]=i_rand(0,9);
        B[i]=i_rand(0,9);
    }
    printf("   ");
    for(int i = 0; i < 51; ++i)
    {
        C[i] = 0;
    }
    for(int i = 0; i< 50; ++i)
    {
        printf("%d", A[i]);
    }
    printf("\n + ");
    for(int i = 0; i< 50; ++i)
    {
        printf("%d", B[i]);
    }
    printf("\n");
    for(int i = 0; i< 55; ++i)
    {
        printf("-");
    }
    printf("\n");
    for(int i = 49; i >= 0; --i)
    {
        if((A[i] + B[i]) > 10)
        {
            C[i + 1] = A[i]+B[i]-10;
            C[i] +=1;
        }
        else
        {
            C[i + 1] = A[i] + B[i];
        }
    }
    for(int i = 0; i < 51; ++i)
    {
        printf("%d", C[i]);
    }
    
    
    return 0;
}