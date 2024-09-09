#include <stdlib.h>
#include <stdio.h>
class list
{
    struct node
    {
        struct node *prev;
        int data;
        struct node *next;
    } *cur;

public:
    list()
    {
        cur = NULL;
    }
    int x = 1;
    void add();
    void front();
    void back();
};

void list::add()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    // printf("Enter Webpage No. ");
    // scanf("%d", &(newnode->data));
    newnode->data = x;
    x++;
    if (cur == NULL)
    {
        newnode->prev = NULL;
        newnode->next = NULL;
        cur = newnode;
    }

    cur->next = newnode;
    newnode->prev = cur;
    newnode->next = NULL;
    cur = newnode;

    printf("Current Webpage: %d", cur->data);
}

void list::back()
{
    cur = cur->prev;
    printf("Current Webpage: %d ", cur->data);
}

void list::front()
{
    cur = cur->next;
    printf("Current Webpage: %d", cur->data);
}