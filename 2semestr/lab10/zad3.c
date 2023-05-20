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

void struct_prn(struct liczba *tab){
    for(int k =0;k<50;k++){
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
    struct liczba tab[50];
    for(int k=0;k<50;k++){
        int c = i_rand(1,2);
        if(c==1){
            tab[k].point = 'i';
        }
        else{
            tab[k].point = 'd';
        }
    }
    for(int k=0;k<50;k++){
         if(tab[k].point=='i'){
            tab[k].i=d_rand(-5,5);
        }
        else{
            tab[k].d=d_rand(-5,5);
        }
    }
    qsort(tab, 50, sizeof(struct liczba), cmpr);
    struct_prn(tab);
    

}