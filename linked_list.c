#include "linked_list.h"

void linkedlist_add(Node** head, char ch){
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->value = ch;
    if(*head){
        Node *last = *head;
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
    int i=0;
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
    Node* before = (*head);
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
void linkedlist_insert_value_atfer_node(Node** head, Node* node, char ch) {
    for (Node* p = *head;p;p = p->next) {
        if (p == node) {
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->value = ch;
            new_node->next = p->next;
            p->next = new_node;
        }
    }
}
