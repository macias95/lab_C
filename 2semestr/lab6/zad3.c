#include<stdio.h>

float *min(float*tab,int n){
    float *min = tab;
    for(int i=1;i<n;i++){
        if(*min>*(tab+i)){
            min = tab+i;
        }
    }
    return min;
}

float *max(float*tab,int n){
    float *max = tab;
    for(int i=1;i<n;i++){
        if(*max<*(tab+i)){
            max = tab+i;
        }
    }
    return max;
}
float roznica(float*a, float*b){
    float result = *a-*b;
    return result;
}

float *min_or_max(float*tab, int n, float*f(float*,int)){
    return f(tab, n);
}
int main(void){
    float tab_A [ ] = {-12.0, 41.5, 3.6, 1.23, 6.15, -32.1};
    float tab_B [ ] = {2.0, 4.0, 6.5, -2.1};
    float *tab_min = min_or_max(tab_A, 6, min);
    float *tab_max = min_or_max(tab_A, 6, max);
    float result = roznica(tab_max,tab_min);
    printf("%f   %f   %0.1f",*tab_max, *tab_min, result);

    
}