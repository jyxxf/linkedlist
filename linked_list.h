#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdlib.h>
#include <stdio.h>
typedef struct _node Node;

typedef struct _node
{
    char value;
    Node *next;
} Node;

void linkedlist_add(Node** head, char ch);
void linkedlist_print_all_value(Node **head);
void linkedlist_find_node(Node **head, char ch, Node *result[]);
int linkedlist_count_value(Node **head, char ch);
int linkedlist_delete_node(Node **head, Node *del_node);
void linkedlist_insert_value_atfer_node(Node **head, Node *node, char ch);
void linkedlist_destroy(Node **head);
#endif