#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_LEN 100

typedef struct node {
    struct node *next;
    struct node *pre;
    char string[BUF_LEN];
}node_t;

node_t *g_head = NULL;

void insert_node (node_t **head, char *str)
{
    node_t *tmp = NULL;

    tmp = (node_t*)malloc(sizeof(node_t));

    if (!tmp)
    {
        printf("dddd\n");
        return;
    }

    strncpy(tmp->string, str, BUF_LEN);
    tmp->next = NULL;
    tmp->pre = NULL;

    if (*head == NULL)
    {
        *head = tmp;
    }
    else
    {
        node_t *pHead = *head;
        while(pHead->next != NULL)
            pHead = pHead->next;

        pHead->next = tmp;
        tmp->pre = pHead;
    }
}

void del_node (node_t **head, char *str)
{
    node_t* tmp = NULL;
    if (!*head)
    {
        printf("....\n");
        return;
    }

    node_t* pHead = *head;

    while(pHead != NULL)
    {
        if (!strncmp(pHead->string, str, BUF_LEN))
        {
            tmp = pHead;
            break;
        }
        pHead = pHead->next;
    }
    
    if (!tmp)
    {
        printf("cannot find the string");
        return;
    }
    else if (tmp == *head)    //head
    { 
        printf("delete %s\n", tmp->string);
        *head = tmp->next;
        (*head)->pre = NULL;
        free(tmp);
    }
    else if (tmp->next == NULL)    //tail
    {
        printf("delete %s\n", tmp->string);
        tmp->pre->next = NULL;
        free(tmp);
    }
    else 
    {
        printf("delete %s\n", tmp->string);
        tmp->pre->next = tmp->next;
        tmp->next->pre = tmp->pre;
        free(tmp);
    }
}

void show_list(node_t *head)
{
    if (!head)
    {
        printf("NULL double link list\n");
        return;
    }

    while(head != NULL)
    {
        printf("%s\n", head->string);
        head = head->next;
    }
}

int main()
{
    insert_node(&g_head, "China");
    insert_node(&g_head, "Nanjing");
    insert_node(&g_head, "Guangdong");
    insert_node(&g_head, "Shenzhen");
    insert_node(&g_head, "Sichuan");
    insert_node(&g_head, "Wuhan");
    insert_node(&g_head, "Hunan");

    show_list(g_head);
//    del_node(&g_head, "xxxx");
    del_node(&g_head, "Shenzhen");
    show_list(g_head);
    return 0;
}
