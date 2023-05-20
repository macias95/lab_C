#include<stdio.h>
#include<string.h>

char *kopiuj(char *cel, char*napis){
    char *w;
    strcpy(cel, napis);
    w = strchr(cel, 'n');
    return w;
}

int main(int argc, char *argv[]){
    char tab[100];
    char *w;
    for(int i=0; i<argc;i++){
        printf("argv[%d]: %s\n",i, argv[i]);
    }
    w = kopiuj(tab, argv[1]);
    printf("%s\n", w);
}