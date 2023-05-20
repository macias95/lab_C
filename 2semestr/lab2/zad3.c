#include<stdio.h>
#include<string.h>

int main(int argc, char*argv[]){
    char tab[argc];
    if (argc>1){
    for(int i = 1; i<argc;i++){
        printf("%s\n", argv[i]);
    }
    for(int i = 1;i<argc;i++){
        int flag = 1;
        for(int j = 1; j<argc;j++){
            if(i == j)
            continue;
            if(strcmp(argv[i],argv[j])==0)
                flag = 0;
        }
        if(flag == 1){
            strcat(tab,argv[i]);
        }
    }
    printf("%s,  %p", tab, tab);
    }
    else{
        printf("brak danych");
    }




}
