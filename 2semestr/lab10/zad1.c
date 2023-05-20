#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i_rand(int min, int max){
return rand() % (max-min+1) + min;}

struct point{
    int x;
    int y;
};

struct vert_AC{
    struct point lb_point;
    struct point rh_point;
};

struct rect{
    struct vert_AC position;
    int pole;
    int obwod;
};

int rect_per(struct vert_AC r){
    return(2*(r.rh_point.x-r.lb_point.x)+2*(r.rh_point.y-r.lb_point.y));
}
int rect_area(struct vert_AC r){
    return((r.rh_point.x-r.lb_point.x)*(r.rh_point.y-r.lb_point.y));
}
void fill_tab(struct rect* wsk, int n){
    for(int i =0;i<n;i++){
        wsk[i].obwod = rect_per(wsk[i].position);
        wsk[i].pole = rect_area(wsk[i].position);
    }
}

void swap(struct rect *a, struct rect *b){
    struct rect temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort_tab(struct rect* r, int n){
    for(int i =0;i<n;i++){
        struct rect *min = r+i;
        for(int j=i+1;j<n-i;j++){
            if(r[j].pole == min->pole){
                if(r[j].obwod<(*min).obwod){
                    min = r+j;
                }
            if(r[j].pole<(*min).pole){
                min = r+j;
            }
            }
        }
        printf("%d pole_min=%d\n",i, (*min).pole);
        swap(r+i, min);
    }
}
int main(void){
        srand(time(0));
        int rozmiar_tab = 3;
        struct rect tab_rect[rozmiar_tab];
        for(int i=0;i<rozmiar_tab;i++){
            tab_rect[i].position.lb_point.x=i_rand(1, 5);
            tab_rect[i].position.lb_point.y=i_rand(1, 5);
            tab_rect[i].position.rh_point.x=i_rand(5, 10);
            tab_rect[i].position.rh_point.y=i_rand(5, 10);
        }
        fill_tab(tab_rect, rozmiar_tab);
        for(int i=0;i<rozmiar_tab;i++){
            printf("%d Ax=%d Ay=%d Bx=%d By=%d pole=%d obwod=%d\n",i,tab_rect[i].position.lb_point.x,
            tab_rect[i].position.lb_point.y, tab_rect[i].position.rh_point.x, tab_rect[i].position.rh_point.y,
            tab_rect[i].pole, tab_rect[i].obwod);
        }
        sort_tab(tab_rect, rozmiar_tab);
        printf("\n");
         for(int i=0;i<rozmiar_tab;i++){
            printf("%d Ax=%d Ay=%d Bx=%d By=%d pole=%d obwod=%d\n",i,tab_rect[i].position.lb_point.x,
            tab_rect[i].position.lb_point.y, tab_rect[i].position.rh_point.x, tab_rect[i].position.rh_point.y,
            tab_rect[i].pole, tab_rect[i].obwod);
        }

        

    return 0;
}