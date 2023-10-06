#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* llink;
    int data;
    struct node* rlink;
} node;

node* x1 = NULL;
node* x2 = NULL;

node * insert(node* first, int val)
{
    node* cur;
    node* temp = (node*) malloc(sizeof(node));
    temp->data = val;
    temp->rlink = NULL;
    temp->llink = NULL;

    if(first==NULL)
    {
        first= temp;
    }
    else
    {
        for(cur=first;cur->rlink!=NULL;cur=cur->rlink);

        cur->rlink = temp;
        temp->llink = cur;
    }
    return first;

}

void display(node* first)
{
    if(first == NULL) printf("Empty List:");
    node* cur;

    for(cur=first;cur!=NULL; cur = cur->rlink) printf("%d ", cur->data);
    printf("\n");
}

int main()
{
    x1 = insert(x1,10);
    x1 = insert(x1,20);
    x1 = insert(x1,30);
    display(x1);

    x2 = insert(x2,100);
    x2 = insert(x2,200);
    x2 = insert(x2,300);
    display(x2);


    node* cur;
    for(cur=x1;cur->rlink!=NULL;cur=cur->rlink);
    cur->rlink = x2;
    x2->llink = cur;
    display(x1);
    return 0;
}
