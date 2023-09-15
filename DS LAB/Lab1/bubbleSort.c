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

void delAtStart()
{

    if(first == NULL) return;

    node* temp = first;
    first = first->next;
    free(temp);
}

void delAtEnd()
{
    if(first == NULL) return;

    node* cur = first;
    node* prev = first;

    for(cur=first;cur->next!=NULL; prev = cur,cur = cur->next);

    prev->next = NULL;
    free(cur);
}

void del(int val)
{
    node* cur;
    node* prev;
    for(cur=first, prev= first;cur!=NULL; prev = cur, cur = cur->next)
    {
        if(cur->data == val)
        {
            prev->next = cur->next;
            free(cur);
            return;
        }
    }
}

void delAlternate()
{
    node* cur = first;
    node* prev = first;

    int alt = -1;

    while(cur!=NULL)
    {
        if(alt == 1)
        {
            prev->next = cur->next;
            node* temp = cur;
            cur = cur->next;
            free(temp);
            alt = -1;
        }
        else
        {
            alt = 1;
            prev = cur;
            cur = cur->next;
        }
    }
}

void reverseList()
{
    if(first==NULL) return;
    node* temp = (node*)malloc(sizeof(node));
    node* cur = first->next;
    first->next = NULL;

    while(cur!=NULL)
    {
        temp = cur;
        cur = cur->next;
        temp->next = first;
        first = temp;
    }
}

void sort()
{
    node* cur;
    node* prev;

}

void insertBefore(int val)
{
    node* cur = first;
    node* prev = first;
    node* temp = (node*) malloc(sizeof(node));

    if(first == NULL) return;

    for(;cur->next != NULL && cur->data != val; prev = cur, cur = cur->next);

    if(cur->next!=NULL)
    {
        prev->next = temp;
        temp->next = cur;

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
    insertAtStart(0);
    display();
    delAlternate();
    display();
    reverseList();
    display();
    return 0;
}
