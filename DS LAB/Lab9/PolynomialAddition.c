//not complete

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int exp;
    int data;
    struct node* next;
} node;

node* p1 = NULL;
node* p2 = NULL;
node* res = NULL;

void display(node* first)
{
    if(first == NULL) printf("Empty List:");
    node* cur;

    for(cur=first;cur!=NULL; cur = cur->next) printf("%dx^%d + ", cur->data,cur->exp);
    printf("\n");
}

node* insert(node* first, int exp, int val)
{
    node* cur;
    node* temp = (node *)malloc(sizeof(node));
    temp->exp = exp;
    temp->data = val;
    temp->next = NULL;

    if(first==NULL)
    {
        first = temp;
        return first;
    }


    for(cur=first;cur->next!=NULL; cur = cur->next);
    cur->next = temp;
    return first;

}


node* del(node* first)
{
    if(first == NULL) return first;;

    node* cur = first;
    node* prev = first;

    for(cur=first;cur->next!=NULL; prev = cur,cur = cur->next);

    prev->next = NULL;
    free(cur);
    return first;

}

int main()
{
    p1 = insert(p1, 3, 1);
    p1 = insert(p1, 2, 5);
    p1 = insert(p1, 1, 3);
    p1 = insert(p1, 0, 2);

    p2 = insert(p2, 3, 9);
    p2 = insert(p2, 2, 8);
    p2 = insert(p2, 1, 7);
    p2 = insert(p2, 0, 6);

    while(p1!=NULL && p2!=NULL)
    {
        int a,b;
        node* temp = (node*) malloc(sizeof(node));


        if(p1->exp == p2->exp)
        {
            temp->exp = p1->exp;
            temp->data = p1->data + p2->data;
        }
    }
    return 0;
}
