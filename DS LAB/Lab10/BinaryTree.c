//not complete


#include<stdio.h>
#include<string.h>

typedef struct tree
{
    struct tree* lchild;
    int data;
    struct tree* rchild;
} tree;

tree* root = (tree*)malloc(sizeof(tree));
root->data = 1;


void createTree()
{
    int data;
    if(root==NULL)
    {
        printf("Enter data for root\n");
        scanf("%d",&data);
        tree* temp = (tree*)malloc(sizeof(tree));
        temp->data = data;
        root=temp;
    }

    char dir[20];
    printf("Enter dir to enter or invalid to quit\n");
    scanf("%s",dir);
    printf("Enter data for data\n");
    scanf("%d",&data);

    int i=0;
    tree* prev = NULL;
    tree* temp = (tree*)malloc(sizeof(tree));
    temp->data = data;
    tree* cur = root;
    while(dir[i]!='\0')
    {
        prev = cur;
        printf("%c\n",dir[i]);
        if(dir[i] == 'l')
        {
            cur = cur->lchild;
        }
        else if(dir[i] == 'r')
        {
            cur = cur->rchild;
        }
        else
        {
            printf("Invalid input\nQuiting...\n");
            return;
        }
        i++;
    }

    if(dir[i-1] == 'l') prev->lchild = temp;
    else prev->rchild = temp;

    createTree(root);

}

void inorder()
{
    tree* cur = root;
    tree* stack[20];
    int top = -1;

    while(1==1)
    {
        printf("outer\n");
        while(cur!=NULL)
        {
            printf("%d\n",cur->data);
            stack[++top] = cur;
            cur = cur->lchild;
        }
        if(top>-1)
        {
            cur = stack[top--];
        }
        else
        {
            break;
        }

        printf(cur->data);
        cur = cur->rchild;
    }
}

int main()
{
//    createTree();
    inorder();
    return 0;
}
