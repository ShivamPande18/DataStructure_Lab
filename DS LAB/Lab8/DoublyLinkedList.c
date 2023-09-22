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
        first->llink = temp;
        temp->rlink = first;
        first = temp;
        return;
    }

    for(;cur->rlink != NULL && cur->data != src; cur = cur->rlink);

    if(cur->rlink!=NULL || src == cur->data)
    {
        cur->llink->rlink = temp;
        temp->llink = cur->llink;
        temp->rlink = cur;

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

void delAtPos(int ind)
{
    int cnt=0;
    node* cur = first;

    if(first==NULL) return;

    if(ind == 0)
    {
        node* temp = first;
        if(first->rlink!=NULL)first->rlink->llink = NULL;
        first = first->rlink;
        free(temp);
        return;

    }

    for(cur=first;cnt!=ind && cur!=NULL;cnt++,cur=cur->rlink);
    if(cur!=NULL)
    {
        cur->llink->rlink = cur->rlink;
        cur->rlink->llink = cur->llink;
        free(cur);
    }

}

void reverseList()
{
    if(first==NULL) return;
    node* temp = (node*)malloc(sizeof(node));
    node* cur = first->rlink;
    first->rlink = NULL;
    first->llink = cur;

    while(cur!=NULL)
    {
        temp = cur;
        cur = cur->rlink;
        temp->rlink = first;
        temp->llink = cur;
        first = temp;
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
    display();
    delAtPos(1);
    display();
    reverseList();
    display();
    return 0;
}
