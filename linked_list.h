#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef char type;

struct _node
{
    type value;
    struct _node *next;
};

void delete_linkedlist_node(struct _node *node_before_want_delete);
void insert_linkedlist_node(struct _node *node, type ch);
void destroy_linkedlist(struct _node *head);
struct _node *create_linkedlist(void);
struct _node *get_node_at_pisition_i(struct _node *head, size_t index);
struct _node *get_node_match_fun(struct _node *head, type value, size_t *index, int fun(type, type));
struct _node *get_node_before_parameter_node(struct _node *head, struct _node *node);

#endif