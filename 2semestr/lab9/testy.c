#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef double (*f)(double);
typedef f f_array[5];
typedef f* f_ptr;
double fun0(double x){return log(x);}
double fun1(double x){return x*x;}
double fun2(double x){return sin(x);}
double fun3(double x){return cos(x);}

f_ptr find_max(f_ptr TAB_FUN, double value){
    f_ptr max;
    max = TAB_FUN;
    int i = 1;
    while(TAB_FUN){
        if((*max)(value)<(*TAB_FUN)(value)){
            max = TAB_FUN;
        }
        TAB_FUN++;
    }
    return max;
    
}
int main(void){
    char* nazwa[]={"log","pow","sin","cos"};
    double data[8]={3.5,1.0,2.5,2.0,1.5,3.0,0.5,4.0};
    f_array TAB_FUN;
    TAB_FUN[0] = fun0;
    TAB_FUN[1] = fun1;
    TAB_FUN[2] = fun2;
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = NULL;
    f_ptr wsk_fun;
    char** str;
    str = nazwa;
    wsk_fun = TAB_FUN;
    f_ptr max_wsk = find_max(TAB_FUN, 0.5);
    printf("%s = %f", nazwa[max_wsk-TAB_FUN], (*max_wsk)(0.5));
    printf("%f\n%f\n%f\n%f\n",TAB_FUN[0](0.5), TAB_FUN[1](0.5), TAB_FUN[2](0.5), TAB_FUN[3](0.5));
    
}
