#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Node *head=NULL;
    char ch;
    while(1){
        ch = getchar();
        linkedlist_add(&head, ch);
        if(ch=='\n')
            break;
    }
    linkedlist_print_all_value(&head);
    Node* result = NULL;
    linkedlist_find_node(&head, '7', &result);
    linkedlist_insert_value_atfer_node(&head, result, '7');
    linkedlist_print_all_value(&head);
    linkedlist_destroy(&head);
    return 0;
}
