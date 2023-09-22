#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* llink;
    int data;
    struct node* rlink;
} node;

node* first = NULL;

void insertAtEnd(int val)
{
    node* cur;
    node* temp = (node*) malloc(sizeof(node));
    temp->data = val;
    temp->rlink = NULL;
    temp->llink = NULL;

    if(first==NULL)
    {
        first = temp;
        return;
    }

    for(cur=first;cur->rlink!=NULL;cur=cur->rlink);

    cur->rlink = temp;
    temp->llink = cur;

}

void delAtEnd()
{
    if(first == NULL) return;

    node* cur = first;

    for(cur=first;cur->rlink!=NULL; cur = cur->rlink);

    cur->llink->rlink = NULL;
    free(cur);
}

void insertBefore(int src, int val)
{
    node* cur = first;
    node* temp = (node*) malloc(sizeof(node));
    temp->data = val;

    if(first == NULL) return;

    if(first->data == src)
    {
        temp->llink = NULL;
        temp->rlink = first;
        first = temp;
        return;
    }

    for(;cur->rlink != NULL && cur->data != src; cur = cur->rlink);

    if(cur->rlink!=NULL || src == cur->data)
    {
        cur->llink->rlink = temp;
        temp->rlink = cur;
        temp->llink = cur->llink;

    }
}

void insertAfter(int src, int val)
{
    node* cur = first;
    node* temp = (node*) malloc(sizeof(node));
    temp->data = val;

    if(first == NULL) return;

    for(;cur->rlink != NULL && cur->data != src; cur = cur->rlink);

    if(cur->rlink!=NULL || src == cur->data)
    {
        node* curNext;
        curNext = cur->rlink;
        cur->rlink = temp;
        temp->rlink = curNext;
        temp->llink = cur;
    }
}

void insertAtPos(int ind, int val)
{
    int cnt=1;
    node* cur = first;
    node* temp = (node*) malloc(sizeof(node));
    temp->data = val;
    temp->rlink = NULL;

    if(first==NULL)
    {
        if(ind==0) first = temp;
        return;
    }

    if(ind == 0)
    {
        temp->llink = NULL;
        temp->rlink = first;
        first = temp;
        return;

    }

    for(cur=first;cnt<ind && cur!=NULL;cnt++,cur=cur->rlink);
    if(cur!=NULL)
    {
        if(cur->rlink!=NULL) cur->rlink->llink = temp;
        temp->rlink = cur->rlink;
        cur->rlink = temp;
        temp->llink = cur;
    }
}

void display()
{
    if(first == NULL) printf("Empty List:");
    node* cur;

    for(cur=first;cur!=NULL; cur = cur->rlink) printf("%d ", cur->data);
    printf("\n");
}

int main()
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertBefore(10,30);
    insertAtPos(3,100);
    display();
    return 0;
}
