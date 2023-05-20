#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double fun0(double x){return log(x);}
double fun1(double x){return x*x;}
double fun2(double x){return sin(x);}
double fun3(double x){return cos(x);}

void print_fun(double f(double), char* name, double* data, int n){
    printf("Wynik: ");
    for(int i=0;i<n;i++){
        printf("%s(%f) = %f   ", name, *(data+i), f(*(data+i)));
    }
}

void print_all_fun(char **str, double (**wsk_fun)(double), double* data, int n){
    while(wsk_fun){
        print_fun(*wsk_fun, *str, data, n);
        printf("\n");
        wsk_fun++;
        str++;
    }
}



int main(void){
    char* nazwa[]={"log","pow","sin","cos"};
    double data[8]={3.5,1.0,2.5,2.0,1.5,3.0,0.5,4.0};
    double (*TAB_FUN[5])(double);
    TAB_FUN[0] = fun0;
    TAB_FUN[1] = fun1;
    TAB_FUN[2] = fun2;
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = NULL;
    double (**wsk_fun)(double);
    char** str;
    str = nazwa;
    wsk_fun = TAB_FUN;
    print_all_fun(str, wsk_fun, data, 8);
    

}