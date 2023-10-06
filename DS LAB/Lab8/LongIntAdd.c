#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* llink;
    int data;
    struct node* rlink;
} node;

node* n1 = NULL;
node* n2 = NULL;
node* res = NULL;

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

node * insertAtFirst(node* first, int val)
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
        temp->rlink = first;
        first->llink = temp;
        first = temp;
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
    char long1[20];
    char long2[20];
    printf("Enter 2 long ints\n");
    scanf("%s",long1);
    scanf("%s",long2);

    int i=0;

    while(long1[i]!='\0')
    {
        n1 = insert(n1,long1[i] - '0');
        i++;
    }
    i = 0;
    while(long2[i]!='\0')
    {
        n2 = insert(n2,long2[i] - '0');
        i++;
    }

    node*cur1;
    node*cur2;

    for(cur1=n1; cur1->rlink != NULL; cur1 = cur1->rlink);
    for(cur2=n2; cur2->rlink != NULL; cur2 = cur2->rlink);

    int sum=0,carry=0;

    while(cur1 != NULL || cur2 != NULL)
    {
        int x,y;

        if(cur1 == NULL) x = 0;
        else x = cur1->data;

        if(cur2 == NULL) y = 0;
        else y = cur2->data;

        sum = x+y+carry;

        if(sum>=10)
        {
            carry = sum/10;
            sum  = sum%10;
        }
        else
        {
            carry = 0;
        }
        res = insertAtFirst(res,sum);

        if(cur1!=NULL) cur1 = cur1->llink;
        if(cur2!=NULL) cur2 = cur2->llink;
    }
    if(carry!=0) res = insertAtFirst(res,carry);
    display(res);


    return 0;
}
