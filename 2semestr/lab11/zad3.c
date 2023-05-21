#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    char value;
    struct tnode *next;
};

struct tnode *insert_item_begin(struct tnode *head, char val)
{
    struct tnode *temp = malloc(sizeof(struct tnode));
    if (!temp)
    {
        printf(" Brak  pamieci !!! \n");
        return head;
    }
    temp->value = val;
    temp->next = head;
    return temp;
}

struct tnode *insert_item_end_scnd(struct tnode *head, char val)
{
    struct tnode *temp = malloc(sizeof(struct tnode));
    if (!temp)
        return head;
    temp->value = val;
    temp->next = NULL;
    if (head)
    {
        struct tnode *ele = head;
        while (ele->next)
            ele = ele->next;
        ele->next = temp;
    }
    else
        head = temp;
    return head;
}

void print_list(const struct tnode *elem)
{
    if (!elem)
    {
        printf(" Lista ␣ jest ␣ pusta .");
        return;
    }
    printf("head -> ");
    for (; elem; elem = elem->next)
        printf("['%c'] ->  ", elem->value);
    printf("NULL");
}

struct tnode *delete_all(struct tnode *elem)
{
    while (elem)
    {
        struct tnode *next = elem->next;
        free(elem);
        elem = next;
    }
    return NULL;
}

int main(void)
{
    struct tnode *head = NULL;
    struct tnode *head_1 = NULL;
    char list[] ="acvft";
    head = insert_item_begin(NULL, list[0]);
    for (int i = 1; i < 5; i++)
    {
        head = insert_item_begin(head, list[i]);
    }
    head_1 = insert_item_end_scnd(NULL,list[0]);
    for (int i = 1; i < 5; i++)
    {
        head_1 = insert_item_end_scnd(head_1, list[i]);
    }
    print_list(head);
    printf("\n");
    print_list(head_1);
    head = delete_all(head);
    head_1 = delete_all(head);
}