#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* first = NULL;



int delete()
{
    int data = -99999;
    if(first == NULL)
    {
        printf("Queue Empty");
        return data;
    }

    node* temp = first;
    first = first->next;
    data = temp->data;
    free(temp);
    return data;
}

void insert(int val)
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
    insert(10);
    display();
    insert(20);
    display();
    printf("delete = %d\n",delete());
    display();

    return 0;
}

