#include<stdio.h>

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
    }

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf ("%4d ", *poczatek++);
        printf ("\n");
    }

int find_min_ind(int*p, int len){
    int min = *p;
    int id_min = 0;
    for(int i = 1; i < len; i++){
        if(*(p+i)<min){
            id_min = i;
        }
    }
    return id_min;
}

void sort(int*p, int*k){
    int len = k-p;
    printf("%d\n", len);
    for(int i=0;(p+i)<k;i++){
        for(int j=0;j<len-i;j++){
            int min_id = find_min_ind(p+i, len-i);
            swap(p+i,p+i+min_id);
        }
    }
    wypisz_i(p, k);

     

}

int main(void){
    int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,
                   64,80,22,12,6,8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,
                   22,34,78,11,21,9,12,5,3,9};
    int tabB[] = {3, 2, 1, 4};
    int len_tab = sizeof(tab_A)/sizeof(int);
    int *p, *k;
    p = tab_A;
    k = p+50;
    sort(p,k);
    //while(i <= len_tab){
      //  if(i%10 == 0){
        //    wypisz_i(tab_A+i-10, tab_A+i);
          //  int min_id = find_min_ind(tab_A+i-10, 10);
            //printf("min index: %d\n\n", min_id);
            
        //}
        //i++;
    //}


}
