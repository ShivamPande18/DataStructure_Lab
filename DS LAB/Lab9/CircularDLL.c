#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* llink;
    int data;
    struct node* rlink;
} node;

node* first = NULL;
node* last = NULL;

void insertAtEnd(int val)
{
    node* cur;
    node* temp = (node*) malloc(sizeof(node));
    temp->data = val;
    temp->rlink = NULL;
    temp->llink = NULL;

    if(last==NULL)
    {
        first = last = temp;
        last->rlink = last;
        last->llink = last;
        return;
    }

    last->rlink = temp;
    temp->llink = last;
    temp->rlink = first;
    last = last->rlink;
    first->llink = last;
}

void delAtEnd()
{
    if(last == NULL) return;
    node* temp = last;
    last->llink->rlink = first;
    last = last->llink;
    free(temp);
}


void display()
{
    if(last == NULL)
    {
        printf("Empty List:\n");
        return;
    }
    node* cur;

    for(cur=last->rlink;cur!=last; cur = cur->rlink) printf("%d ", cur->data);
    printf("%d ", cur->data);
    printf("\n");
}

int main()
{
    int ch;
    int val;

    while(1==1)
    {
        printf("Choose:-\n1) Display\n2) Insert\n3) Delete\n4) Quit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                display();
                break;
            case 2:
                printf("Enter val to insert\n");
                scanf("%d",&val);
                insertAtEnd(val);
                break;
            case 3:
                delAtEnd();
                break;
            default:
                printf("Quiting");
                exit(0);
        }
    }
    return 0;
}
