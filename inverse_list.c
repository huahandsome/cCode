#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char string[100];
    struct node *next;
}node_t;

node_t *g_head = NULL;

void add_node(node_t **head, char *string)
{
    node_t *pHead = *head;
    node_t *tmp = NULL;

    if (!pHead)
    {
        tmp = (node_t*)malloc(sizeof(node_t));
        if (!tmp) 
        {
            printf("NULL");
            return;
        }
        tmp->next = NULL;
        strcpy(tmp->string, "This is head");
        *head = tmp;

        tmp = (node_t *)malloc(sizeof(node_t));
        if (!tmp)
        {
            printf("NULL");
            return;
        }
        tmp->next = NULL;
        strcpy(tmp->string, string);

        (*head)->next = tmp;
    }
    else
    {
        tmp = (node_t *)malloc(sizeof(node_t));
        if (!tmp)
        {
            printf("NULL");
            return;
        }
        tmp->next = NULL;
        strcpy(tmp->string, string);

        node_t *p = pHead;
        while(p->next)
        {
            p = p->next;
        }

        p->next = tmp;
    }
}

void list_nodes(node_t *head)
{
    node_t *p = head;
    while(p)
    {
        printf("%s\n", p->string);
        p = p->next;
    }
}

void inverse_list(node_t *head)
{
    if (!head)
    {
        printf("......NULL....\n");
        return;
    }

    node_t *tail = head->next;
    int len = 0;

    while(tail)
    {
        tail = tail->next;
        len++;
    }
        
    node_t *newHead = head;
    node_t *first = head->next;
    node_t *pre = NULL;
    tail = first;

    while(len > 0)
    {
        len--;

        while(tail->next)
        {
            pre = tail;
            tail = tail->next;
        }
        pre->next = NULL;

        newHead->next = tail;
        newHead = newHead->next;
        tail = first;
    }
}

int main()
{
    add_node(&g_head, "Beijing");
    add_node(&g_head, "Shanghai");
    add_node(&g_head, "Nanjing");
    add_node(&g_head, "Wuhan");
    list_nodes(g_head);

    inverse_list(g_head);
    list_nodes(g_head);
    return 0;
}
