//incomplete code

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* first = NULL;

void display()
{
    if(first == NULL) printf("Empty List:");
    node* cur;

    for(cur=first;cur!=NULL; cur = cur->next) printf("%d ", cur->data);
    printf("\n");
}

void insertAtEnd(int val)
{
    node* cur;
    node* temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;

    if(first==NULL)
    {
        first = temp;
        return;
    }


    for(cur=first;cur->next!=NULL; cur = cur->next);
    cur->next = temp;
}

void insertAtStart(int val)
{
    node* cur;
    node* temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = first;
    first = temp;
}

void insertAtPos(int ind, int val)
{
    int cnt=1;
    node* cur = first;
    node* prev = first;
    node* temp = (node*) malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;

    if(first==NULL)
    {
        if(ind==0) first = temp;
        return;
    }

    if(ind == 0)
    {
        temp->next = first;
        first = temp;
        return;

    }

    for(cur=first;cnt<ind && cur!=NULL;cnt++,cur=cur->next);

    if(cur!=NULL)
    {
        temp->next = cur->next;
        cur->next = temp;
    }
}

int main()
{
    insertAtEnd(10);
    display();
    insertAtEnd(20);
    display();
    insertAtEnd(30);
    display();
    insertAtEnd(40);
    display();
    insertAtEnd(50);
    display();
    insertAtStart(0);
    display();
    insertAtPos(0,123);
    display();
    return 0;
}
