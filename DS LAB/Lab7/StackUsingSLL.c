#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* first = NULL;



int pop()
{
    int data = -99999;
    if(first == NULL)
    {
        printf("Stack Empty");
        return data;
    }

    node* cur = first;
    node* prev = first;

    for(cur=first;cur->next!=NULL; prev = cur,cur = cur->next);

    prev->next = NULL;
    data = cur->data;
    free(cur);
    return data;
}

void push(int val)
{
    node* cur;
    node* temp = (node*) malloc(sizeof(node));
    temp->next = NULL;
    temp->data = val;

    if(first == NULL)
    {
        first = temp;
        return;
    }

    for(cur=first;cur->next!=NULL;cur=cur->next);
    cur->next = temp;
}

void display()
{
    if(first == NULL) printf("Empty List:");
    node* cur;

    for(cur=first;cur!=NULL; cur = cur->next) printf("%d ", cur->data);
    printf("\n");
}

int main()
{
    push(10);
    display();
    push(20);
    display();
    printf("pop = %d\n",pop());
    display();

    return 0;
}
