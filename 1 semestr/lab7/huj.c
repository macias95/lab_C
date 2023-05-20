#include<stdio.h>

double licz(double *tab, double *p, double *k, double *s, double *il, double *sr){
    double suma = 0, iloczyn = 1, srednia;
    for(p; p<k+1; p++){
        suma += *p;
        iloczyn *= *p; 
    }
    *s = suma;
    *il = iloczyn;
    *sr = suma/(20-10);
}

int main(){
    double tab[] = {-95.62, 0.16, 34.55, -15.11, -15.15, 23.79, 49.91, -36.87, 40.22, 95.89,
54.57, 75.95, -50.48, -57.83, -19.57, -69.53, 78.04, -7.06, 71.59, -80.12, 9.39, 34.63,
-87.91, -57.20, 13.73, 83.30, 56.21, -53.08, 39.89, -53.83, 28.00, 43.26, 45.34, -36.45,
-70.84, -68.81, 86.34, 78.06, -6.68, 27.57, 74.95, -51.11, 4.52, -74.52, -9.94, 83.95,
-45.06, -30.90, -22.11, -72.47};
    double *p, *k;
    p = tab+10;
    k = tab+20;
    double iloczyn = 1, suma = 0, srednia = 0;
    double *s, *il, *sr;
    s = &suma;
    il = &iloczyn;
    sr = &srednia;
    licz(tab, p, k, s, il, sr);
    printf("sum= %f, il=%f, sr=%f", *s, *il, *sr);



}