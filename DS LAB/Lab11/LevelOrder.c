//create function not there. Hard coded

#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    int val;
    struct tree *left;
    struct tree *right;
} tree;

tree *root;
tree* arr[100];
int front = -1;
int rear = -1;

void insert(tree* val)
{
    arr[++rear] = val;
}

tree* delete()
{
    return arr[++front];
}

tree *create(int val)
{
    tree *temp = (tree *)malloc(sizeof(tree));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void bfs(tree* root)
{
    tree* cur = root;
    while(cur)
    {
        //insert(cur);
        printf("%d ", cur->val);
        if(cur->left) insert(cur->left);
        if(cur->right) insert(cur->right);
        cur = delete();
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
            cur = cur->left;
        }
        if(top>-1) cur = stack[top--];
        else break;

        printf("%d",cur->val);
        cur = cur->right;
    }
}

int main()
{
    root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    //  inOrder();
    bfs(root);

    return 0;
}
