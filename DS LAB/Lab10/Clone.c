#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *lchild;
    int data;
    struct tree *rchild;
} tree;

tree * t1;
tree * t2;

tree* createTree(tree* root)
{
    int i = 0;
    printf("Enter number of nodes:\n");
    int n;
    scanf("%d", &n);

    while (i < n) 
    {
        char dir[10];
        printf("enter dir\n");
        scanf("%s", dir);
        int data;
        printf("enter datar\n");
        scanf("%d", &data);

        tree *cur = root;
        tree *prev = cur;

        tree *temp = (tree *)malloc(sizeof(tree));
        temp->data = data;
        temp->rchild = NULL;
        temp->lchild = NULL;

        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            int j = 0;
            while (dir[j] != '\0')
            {
                prev = cur;
                if (dir[j] == 'l')
                    cur = cur->lchild;
                else
                    cur = cur->rchild;
                j++;
            }
            if (dir[j - 1] == 'l')
                prev->lchild = temp;
            else
                prev->rchild = temp;
        }
        i++;
    }
    return root;
}

tree *cloneBinaryTree(tree *root)
{
    if (root == NULL)
        return NULL;
    tree* newNode = (tree*)malloc(sizeof(tree));
    newNode->data = root->data;
    newNode->rchild = newNode->lchild = NULL;
    tree *temp = newNode;
    temp->lchild = cloneBinaryTree(root->lchild);
    temp->rchild = cloneBinaryTree(root->rchild);
    return temp;
}

void inOrder(tree *root)
{
    tree *cur = root;
    tree *stack[20];
    int top = -1;
    int i = 0;

    while (1 == 1)
    {
        while (cur != NULL)
        {
            stack[++top] = cur;
            cur = cur->lchild;
        }
        if (top > -1)
            cur = stack[top--];
        else
            break;

        printf("%d ",cur->data);
        cur = cur->rchild;
    }

    printf("\n");
}

int main()
{
    t1 = createTree(t1);
    t2 = cloneBinaryTree(t1);
    inOrder(t1);
    inOrder(t2);
}
