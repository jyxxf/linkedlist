#include "linked_list.h"

void linkedlist_add(Node** head, char ch){
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->value = ch;
    if((*head)->next){
        Node *last = (*head)->next;
        while(last->next)
            last = last->next;
        last->next = p;
    }else
        (*head) = p;
}

void linkedlist_print_all_value(Node **head){
    printf("all value: ");
    for (Node *p = (*head); p; p = p->next)
        printf("%c ", p->value);
    printf("\n");
}

int linkedlist_count_value(Node **head, char ch){
    size_t i=0;
    for (Node *p = (*head); p;p=p->next){
        if(p->value==ch)
            i++;
    }
    return i;
}

void linkedlist_find_node(Node **head, char ch,Node* result[]){
    size_t i = 0;
    for (Node *p = (*head); p;p=p->next){
        if(p->value==ch){
            result[i] = p;
            i++;
        }
    }
}

int linkedlist_delete_node(Node **head, Node* del_node){
    Node *before;
    if((*head)==del_node){
        (*head) = del_node->next;
        free(del_node);
        return 1;
    }
    for (Node *p = (*head); p; p = p->next){
        if (p == del_node){
            before->next = del_node->next;
        free(del_node);
        return 1;
        }else
        before = p;
    }
    return 0;
}

void linkedlist_destroy(Node **head){
    Node *before = (*head);
    for (Node *p = before; p; before = p){
        p = p->next;
        free(before);
    }
}
