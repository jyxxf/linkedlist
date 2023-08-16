#include "linked_list.h"
#include <stdlib.h>

/**
 * @brief 删除node_before_want_delete后的节点
 *
 * @param node_before_want_delete
 */
void delete_linkedlist_node(struct _node *node_before_want_delete)
{
    struct _node *temp = node_before_want_delete->next->next;
    free(node_before_want_delete->next);
    node_before_want_delete->next = temp;
}

void destroy_linkedlist(struct _node *head)
{
    struct _node *p = head;
    struct _node *p_next = p->next;
    while (p->next)
    {
        free(p);
        p = p_next;
        p_next = p->next;
    }
    free(p);
}

/**
 * @brief 在node节点（可以是头节点）后插入新的节点
 *
 * @param node
 * @param ch
 */
void insert_linkedlist_node(struct _node *node, type ch)
{
    struct _node *temp = node->next;
    node->next = malloc(sizeof(struct _node));
    node->next->value = ch;
    node->next->next = temp;
}

struct _node *create_linkedlist(void)
{
    struct _node *head = malloc(sizeof(struct _node));
    head->next = NULL;
    return head;
}

/**
 * @brief 获得从head开始第i个节点指针
 *
 * @param head
 * @param index head节点本身为位置0
 * @return struct _node*
 */
struct _node *get_node_at_pisition_i(struct _node *head, size_t index)
{
    while (index--)
    {
        if (head)
            head = head->next;
    }
    return head;
}

/**
 * @brief 找到满足fun关系式的node返回并设置它的索引
 *
 * @param head
 * @param value
 * @param index head本身为索引0
 * @param fun 满足条件时返回1
 * @return struct _node*
 */
struct _node *get_node_match_fun(struct _node *head, type value, size_t *index, int fun(type, type))
{
    *index = 0;
    while (head)
    {
        if (fun(head->value, value))
            break;
        else
            head = head->next;
        (*index)++;
    }
    return head;
}

/**
 * @brief 找到前一个节点
 *
 * @param head
 * @param node
 * @return struct _node*
 */
struct _node *get_node_before_parameter_node(struct _node *head, struct _node *node)
{
    while (head)
    {
        if (head->next == node)
            break;
        head = head->next;
    }
    return head;
}
