#include<stdio.h>
#include<stdlib.h>

struct name_data{
    char *lname;
    char* fname[2];
};

struct personel
{
    int num;
    struct name_data mgr;
    struct name_data *emp;
};


int main(void){
    struct personel *staff, w;
    staff = &w;
    w.num=2;
    staff->emp = calloc(staff->num,sizeof(struct name_data));
    staff->emp[1].fname[1] = "Jim";
    staff->mgr.lname = calloc(10,sizeof(char));
    scanf("%s",staff->mgr.lname);
    printf("\n print: %s",staff->mgr.lname);
    free(staff->emp);
    free(staff->mgr.lname);
    
    
    return 0;
}