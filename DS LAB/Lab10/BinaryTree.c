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

void inorder(tree* cur)
{
    if(cur!=NULL)
    {
        inorder(cur->lchild);
        printf("%d ",cur->data);
        inorder(cur->rchild);
    }
}


void createTree()
{
    int i=0;
    printf("Enter number of nodes\n");
    int n;
    scanf("%d",&n);

    while(i<n)
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
        while(cur)
        {
            if(cur->rchild)
            {
                stack[++top] = cur->rchild;
            }
            stack[++top] = cur;
            cur = cur->lchild;
        }
        cur = stack[top--];

        if (cur->rchild && stack[top] == cur->rchild)
        {
            stack[top--];
            stack[++top] = cur;
            cur = cur->rchild;
        }
        else // Else print root's data and set root as NULL
        {
            printf("%d ", cur->data);
            cur = NULL;
        }

        if(top<=-1) break;
    }
}

void preOrder()
{
    tree* cur = root;
    tree* stack[20];
    int top = -1;

    stack[++top] = cur;

    while(top>-1)
    {
        tree* node = stack[top];
        printf("%d",node->data);
        stack[top--];

        if(node->rchild) stack[++top] = node->rchild;
        if(node->lchild) stack[++top] = node->lchild;
    }
}

void findParent(int src, tree* cur)
{
    if(cur == NULL) return;
    if(cur->lchild  && cur->lchild->data == src)
    {
        printf("%d",cur->data);
        return;
    }
    if(cur->rchild  && cur->rchild->data == src)
    {
        printf("%d",cur->data);
        return;
    }

    findParent(src,cur->lchild);
    findParent(src,cur->rchild);
}

int treeDepth(tree* cur)
{
    if(!cur) return 0;
    int ldepth = treeDepth(cur->lchild);
    int rdepth = treeDepth(cur->rchild);

    if(ldepth>rdepth) return ldepth+1;
    else return rdepth+1;
}

int noOfLeafNodes()
{
    tree* cur = root;
    tree* stack[20];
    int top = -1;
    int count = 0;

    while(1==1)
    {
        while(cur!=NULL)
        {
            stack[++top] = cur;
            cur = cur->lchild;
        }
        if(top>-1) cur = stack[top--];
        else break;

        count++;
        cur = cur->rchild;
    }
    return count;
}

int printAncestors(tree *root, int target)
{
  if (root == NULL)
     return 0;

  if (root->data == target)
     return 1;

  if ( printAncestors(root->lchild, target) || printAncestors(root->rchild, target) )
  {
    printf("%d",root->data);
    return 1;
  }
  return 0;
}

int main()
{
    createTree();
//    inOrder();
//    postOrder();
//    preOrder();
//    findParent(3,root);
//    printf("%d",treeDepth(root));
//    printf("%d",res);
//    printf("%d",noOfLeafNodes());
    printAncestors(root,7);
    return 0;
}
