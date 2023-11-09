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

int areMirrors(tree *root1, tree *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;

    if (root1 == NULL || root2 == NULL)
        return 0;

    if (root1->data != root2->data)
        return 0;

    return areMirrors(root1->lchild, root2->rchild) && areMirrors(root1->rchild, root2->lchild);
}

int main()
{
    t1 = createTree(t1);
    t2 = createTree(t2);

    if (areMirrors(t1, t2))
        printf("The trees are mirrors.\n");
    else
        printf("The trees are not mirrors.\n");
    return 0;
}
