

#include <stdio.h>
 int main(void){
    int a[10] = {[5]=3,5};
    for(int i=0;i<10;i++){
    printf("a[%d] = %d\n", i,*(a+i));
    }
 }

