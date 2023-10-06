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
node* inter = NULL;

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
    x1 = insert(x1,1);
    x1 = insert(x1,2);
    x1 = insert(x1,3);
    display(x1);

    x2 = insert(x2,2);
    x2 = insert(x2,3);
    x2 = insert(x2,4);
    display(x2);


    node* cur;
    node* inCur;

    int flag = 0;

    for(cur = x2; cur!=NULL; cur = cur->rlink)
    {
        for(inCur = x1; inCur != NULL; inCur = inCur->rlink)
        {
            if(cur->data == inCur->data)
            {
                inter = insert(inter,cur->data);
                break;
            }
        }
    }

    display(inter);

    return 0;
}
