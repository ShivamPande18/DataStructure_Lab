#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* llink;
    int exp;
    int data;
    struct node* rlink;
} node;

void display(node* first)
{
//    if(first->llink == first)
//    {
//        printf("Empty List:\n");
//        return;
//    }
    node* cur;

    for(cur=first->rlink;cur->exp!=-1; cur = cur->rlink) printf("x^%d*%d +",cur->exp, cur->data);
    printf("\n");
}


node * genPoly(int degree, int arr[degree+1])
{
    node* head = (node*)malloc(sizeof(node));
    head-> exp = -1;
    head->rlink = head->llink = head;

    node * cur = head;

    for(int i=degree; i>=0; i--)
    {
        int cons = arr[i];
        if(cons!=0)
        {
            node * temp = (node *)malloc(sizeof(node));
            temp-> exp = i;
            temp-> data = cons;
            temp->llink = cur;
            temp-> rlink = head;
            cur-> rlink = temp;
            head->llink = temp;
            cur = temp;
        }
    }
    return head;
}

node* multiply(node* p1, node* p2)
{
    node* head = (node*)malloc(sizeof(node));
    head-> exp = -1;
    head->rlink = head->llink = head;

    node * cur = head;

    p2 = p2->rlink;

    while(p2->exp != -1)
    {
        p1 =p1->rlink;
        while(p1->exp != -1)
        {
            int curExp = p1->exp + p2-> exp;
            if(curExp == cur->exp)
            {
                cur->data += (p1->data * p2->data);
            }
            else
            {
                node* temp = (node*)malloc(sizeof(node));
                temp-> exp = p1->exp + p2-> exp;
                temp-> data = p1->data * p2->data;
                temp->llink = cur;
                temp-> rlink = head;
                cur -> rlink = temp;
                head->llink = temp;
                cur = temp;
            }

            p1 = p1->rlink;
        }
        p2 = p2->rlink;
    }

    return head;
}

int main()
{
    int c1[] = {1,1,1};
    int c2[] = {1,0,1};
    node * p1 = genPoly(2,c1);
    node * p2 = genPoly(2,c2);
    display(p1);
    display(p2);

    node* mul = multiply(p1,p2);
    display(mul);
}
