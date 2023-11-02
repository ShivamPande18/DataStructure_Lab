//not complete


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tree
{
    struct tree* lchild;
    int data;
    struct tree* rchild;
} tree;

tree* root;


void createTree()
{
    int i=0;
    while(i<5)
    {
        char dir[10];
        printf("enter dir\n");
        scanf("%s",dir);
        int data;
        printf("enter datar\n");
        scanf("%d",&data);

        tree* cur = root;
        tree* prev = cur;

        tree* temp = (tree*) malloc(sizeof(tree));
        temp->data = data;
        temp->rchild = NULL;
        temp->lchild = NULL;

        if(root == NULL)
        {
            root = temp;
        }
        else
        {
            int j=0;
            while(dir[j]!='\0')
            {
//                printf("NULL");
                prev = cur;
                if(dir[j] == 'l') cur = cur->lchild;
                else cur = cur->rchild;
                j++;
            }
            if(dir[j-1] == 'l') prev->lchild = temp;
            else prev ->rchild = temp;
        }
        i++;
    }

}

void inOrder()
{
    tree* cur = root;
    tree* stack[20];
    int top = -1;

    while(1==1)
    {
        while(cur!=NULL)
        {
            stack[++top] = cur;
            cur = cur->lchild;
        }
        if(top>-1) cur = stack[top--];
        else break;

        printf("%d",cur->data);
        cur = cur->rchild;
    }
}

void postOrder()
{
    tree* cur = root;
    tree* stack[20];
    int top = -1;

    while(1==1)
    {
        while(cur!=NULL)
        {
            stack[++top] = cur;
            cur = cur->lchild;
        }
        if(top>-1) cur = stack[top--];
        else break;

        printf("%d",cur->data);
        cur = cur->rchild;
    }
}

int main()
{
    createTree();
    inOrder();
    postOrder();
    return 0;
}
