#include <stdio.h>

struct liczba{
    char point;
    union data
    {
        int i;
        double d;
    } ;
    
};
int main(void){
    struct liczba aj[2];
    aj[1].point = 'i';
    aj[0].d = 1;
    aj[1].i = 1;
    printf("%d  %f",aj[0].d, aj[1].i);
    
}