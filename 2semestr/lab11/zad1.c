#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i_rand(int min, int max){
return rand() % (max-min+1) + min;}

double d_rand(double min, double max){
double r = (double) rand()/RAND_MAX;
return r*(max-min) + min;
}
struct liczba{
    char point;
    union data
    {
        int i;
        double d;
    } ;
    
};

void struct_prn(struct liczba *tab, int n){
    for(int k =0;k<n;k++){
        printf("%c: ",(tab+k)->point);
        if((tab+k)->point=='i'){
            printf("%d\n",(tab+k)->i);
        }
        else{
            printf("%f\n",(tab+k)->d);
        }
    }
}

int cmpr(const void *a, const void *b){
    struct liczba *el_a = (struct liczba *)a;
    struct liczba *el_b = (struct liczba *)b;
    if(el_a->point==el_b->point){
        if(el_a->point == 'i'){
            return((el_a->i)-(el_b->i));
        }
        else return ((el_a->d > el_b->d) - (el_a->d<el_b->d));
    }
    else if((el_a->point=='i')&(el_b->point=='d')){
        return(-1);
    }
    else return(1);
}

int main(void){
    srand(time(0));
    int n=i_rand(10,20);
    struct liczba tab[n];
    for(int k=0;k<n;k++){
        int c = i_rand(1,2);
        if(c==1){
            tab[k].point = 'i';
        }
        else{
            tab[k].point = 'd';
        }
    }
    for(int k=0;k<n;k++){
         if(tab[k].point=='i'){
            tab[k].i=d_rand(-5,5);
        }
        else{
            tab[k].d=d_rand(-5,5);
        }
    }
    struct_prn(tab,n);
    FILE *fp=fopen("C:/tekst/plik.dat", "wb");
    fwrite(tab, sizeof(struct liczba), n, fp);
    fclose(fp);
    FILE *fb = fopen("C:/tekst/plik.dat", "rb");
    fseek(fb,0,SEEK_END);
    int size_tab = ftell(fb);
    
    printf("size tab %d  n=%d",size_tab, n);
    struct liczba TAB[size_tab];
    for(int i=0;i<n;i=+sizeof(struct liczba)){
        fread(TAB+i,sizeof(struct liczba), 1,fb);
    }
    fclose(fb);
    struct_prn(TAB,n);
    qsort(tab, n, sizeof(struct liczba), cmpr);
    }