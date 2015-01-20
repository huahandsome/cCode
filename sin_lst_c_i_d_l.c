/* single link list: create, insert at tail, delete and list */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char string[100];
    struct node *next;
} node_t;

node_t *g_head = NULL;

/**
 * return the head of the link list
*/

void create_list(node_t** head, char *str)
{
    node_t *tmp = (node_t *) malloc(sizeof(node_t));

    if (!tmp)
    {
        *head = NULL;
        return;
    }

    strncpy(tmp->string, str, 100);
    tmp->next = NULL;

    *head = tmp;
}

/**
 * @1 head: head of the link list
*/

void addToEnd(node_t* head, char *str)
{  
     node_t *first = NULL;
     if (head == NULL)
     {
         create_list(&head, str);
         if (!head)
             printf("Error\n");
     }
     else
     {
        node_t *tmp = (node_t *) malloc(sizeof(node_t));

        if (!tmp)
            return;

        strncpy(tmp->string, str, 100);
        tmp->next = NULL;

        first = head; 
        while(first->next != NULL) 
            first = first->next;

        first->next = tmp;
    }
}

int del(node_t *head, char *str)
{
    node_t *tmp = head;
    node_t *pre = NULL;

    if (!tmp)
    {
        printf("Nothing to be deleted\n");
        return 0;
    }
    

    while(tmp != NULL)
    {
        if (!strcmp(str, tmp->string))
            break;
        pre = tmp;
        tmp = tmp->next;
    }

    if (!tmp)
    {
        printf("Cannot find the string\n");
        return -1;
    }
    else
    {
        //first node
        if (tmp == head) 
        {
            head = tmp->next;
            free(tmp);
        }
        else if (tmp->next == NULL)// last node
        {
            free(tmp);
            pre->next = NULL;
        }
        else // mid node
        {
            pre->next = tmp->next;
            free(tmp);
        }
    }
    return 0;
}

void listNode(node_t* head)
{
    while(head)
    {
        printf("%s\n", head->string);
        head = head->next;
    }
}

int main()
{
    create_list(&g_head, "China");

    addToEnd(g_head, "American");
    addToEnd(g_head, "Africa");
    addToEnd(g_head, "Beijing");
    addToEnd(g_head, "Nanjing");
    listNode(g_head);

    del(g_head, "nanjing");
    listNode(g_head);
    addToEnd(g_head, "Shanghai");
    listNode(g_head);
    return 0;
}
