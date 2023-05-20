#include<stdio.h>
#include<strings.h>

int main(void){
    char t[11]="Ala ma pal";
    char k[11];
    FILE *fp = fopen("C:/tekst/pies.txt","w");
    if(fp == NULL){
        printf("Nie poprawnie utworzono plik\n");}
    else{ 
        for(int i = 0;i<11;i++){
            fputc(t[i],fp);
    }}
             
        printf("succes!\n");  
    fclose(fp);
    FILE *f = fopen("C:/tekst/pies.txt","r");
    if(f == NULL){
        printf("Nie poprawnie utworzono plik\n");}
    else{
        {   
            for(int i=0;i<11;i++){
            printf("%c", getc(f));
        }
    }
    fclose(f);

      
}}