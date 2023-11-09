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

int inOrder(tree* root, int arr[20])
{
    tree *cur = root;
    tree *stack[20];
    int top = -1;
    int i=0;

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

        arr[i] = cur->data;
        i++;
        cur = cur->rchild;
    }

    return i;
}

int main()
{
    int arr1[20];
    int arr2[20];
    int len1,len2;

    t1 = createTree(t1);
    t2 = createTree(t2);
    len1 = inOrder(t1,arr1);
    len2 = inOrder(t2,arr2);

    if(len1!=len2)
    {
        printf("Not equal");
        return 0;
    }

    for(int i=0;i<len1;i++)
    {
        if(arr1[i] != arr2[i]) 
        {
            printf("Not equal");
            return 0;
        }
    }
    printf("Equal");
    return 0;
}
