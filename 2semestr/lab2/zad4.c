#include<stdio.h>
#include<string.h>

int main(void){
    char word1[11] = "dwa";
    char word2[11] = "dwiescie";
    char temp[11];
    strcat(temp,word1);
    int len = strlen(word1);
    for(int i = 0;i<11;i++){
        word1[i]=word2[i];
    }
    printf("%s\n", word1);
    printf("%s", temp);
}