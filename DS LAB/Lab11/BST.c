#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int val;
    struct tree *left;
    struct tree *right;
} tree;

tree* root;

tree* create(int val)
{
    tree *temp = (tree *)malloc(sizeof(tree));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

tree *insert(tree *cur, int val)
{
    if (cur == NULL)
        return create(val);

    if (val < cur->val)
        cur->left = insert(cur->left, val);
    else if (val > cur->val)
        cur->right = insert(cur->right, val);

    return cur;
}

tree *deleteNode(tree* root, int key)
{
    if (root == NULL)
        return root;
    if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }

    if (root->left == NULL)
    {
        tree *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        tree *temp = root->left;
        free(root);
        return temp;
    }
    else
    {

        tree *prev = root;

        tree *succ = root->right;
        while (succ->left != NULL)
        {
            prev = succ;
            succ = succ->left;
        }
        if (prev != root)
            prev->left = succ->right;
        else
            prev->right = succ->right;

        // Copy Successor Data to root
        root->val = succ->val;

        free(succ);
        return root;
    }
}

void inorder(tree* cur)
{
    if(cur!=NULL)
    {
        inorder(cur->left);
        printf("%d ",cur->val);
        inorder(cur->right);
    }
}

tree *search(tree *root, int key)
{
    if (root == NULL || root->val == key)
        return root;

    if (root->val < key)
        return search(root->right, key);

    return search(root->left, key);
}

int main()
{
    root = insert(root, 1);
    insert(root, 3);
    insert(root, 2);
    insert(root, 5);
    insert(root, 7);
    inorder(root);
    printf("\n");
    root = deleteNode(root, 5);
    inorder(root);
    printf("\n");

    if (search(root, 7) == NULL)
        printf("not found\n");
    else
        printf("found\n");

    if (search(root, 6) == NULL)
        printf("not found\n");
    else
        printf("found\n");
}
