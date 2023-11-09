#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
} node;

node *create(char data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node *buildExpressionTree(char postfix[])
{
    node *stack[100];
    int top = -1;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        node *temp = create(postfix[i]);
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            stack[++top] = temp;
        }
        else
        {
            temp->right = stack[top--];
            temp->left = stack[top--];
            stack[++top] = temp;
        }
    }
    return stack[top];
}

int evaluateTree(node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root->data - '0';
    }
    else
    {
        int leftValue = evaluateTree(root->left);
        int rightValue = evaluateTree(root->right);
        switch (root->data)
        {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        }
    }
    return 0;
}

int main()
{
    char postfix[] = "23*5+";
    node *root = buildExpressionTree(postfix);
    int result = evaluateTree(root);
    printf("Result: %d\n", result);

    return 0;
}
