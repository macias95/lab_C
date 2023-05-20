#include<stdio.h>
#include<strings.h>

char *kop(char*cel, char*napis){
    strcpy(cel, napis);
    char *w = strchr(cel, 'e');
    return w;
}

int main(){
    char tab[50], *w;
    char *kat = "to test strcp";
    w = kop(tab, kat);
    printf("%s", w);
   
    
}