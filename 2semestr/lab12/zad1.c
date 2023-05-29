#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elem {
    char val;
    int count;
    struct elem* next;
};

struct elem* create_node(char var) {
    struct elem* temp = malloc(sizeof(struct elem));
    temp->val = var;
    temp->count = 1;
    temp->next = NULL;
    return temp;
}

struct elem* add_to_list(struct elem* head, char var) {
    struct elem* temp = create_node(var);
    if (head == NULL) {
        head = temp;
    } else {
        struct elem* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = temp;
    }
    return head;
}

struct elem* delete_all(struct elem* ele) {
    while (ele) {
        struct elem* next = ele->next;
        free(ele);
        ele = next;
    }
    return NULL;
}

struct elem* search_node(struct elem* ele, char key) {
    for (; ele && ele->val != key; ele = ele->next);
    return ele;
}

void print_list(const struct elem* ele) {
    if (!ele) {
        printf("Lista jest pusta.\n");
        return;
    }
    printf("head -> ");
    for (; ele; ele = ele->next) {
        printf("[%c : %d] -> ", ele->val, ele->count);
    }
    printf("NULL\n");
}

int main(void) {
    const char text[] = "Sometimes you will never know the value of a moment until it becomes a memory";
    struct elem* head = NULL;
    head = add_to_list(NULL,text[0]);
    for (int i = 1; i < strlen(text); i++) {
        char key = text[i];
        if (key == ' ') {
            continue;
        }
        struct elem* find = search_node(head, key);
        if (find) {
            find->count += 1;
        } else {
            head = add_to_list(head, key);
        }
    }
    
    print_list(head);
    head = delete_all(head);
    return 0;
}