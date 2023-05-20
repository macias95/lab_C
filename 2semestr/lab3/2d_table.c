#include<stdio.h>

void show_element(int *tab){
      for(int row=0; row<3;row++){
            print_element(tab+row*4,tab+row*4+4);
            printf("\n");
        }
        
      }  
int *min_id(int*p,int*k){
    int *min = p;
    while(p<k){
        if(*min>*p){
            min = p;
        }
        p++;
    }
    return min;
}
int *get_min_index(int *tab, int rows){
    int *min_2d = tab;
    int *min;
    for(int row = 0;row<rows;row++){
        min = min_id(tab+row*4, tab+row*4+4);
        if(*min_2d>*min)min_2d=min;
    }
    return min_2d;
}

void print_element(int *p, int *k){
    while(p<k){
        printf("%d  ",*p++);
    }
}


int main(void){
    int tab[3][4]={ {2,4,1,-6},
                    {0,-9,4,11},
                    {3,10,8,-2}};
    show_element(tab);
    int *tab_id=get_min_index(tab, 3);
    printf("%p -> %d", tab_id, *tab_id);

}