#include<stdio.h>
#define SIZE 100

char stack[SIZE];
char infix[SIZE];
char postfix[SIZE];
int top = -1;

void push(char c)
{
    top++;
    if(top >= SIZE )
    {
        printf("Stack out of bound");
        return;
    }

    stack[top] = c;
}

char pop()
{
    if(top < 0)
    {
        printf("Stack empty");
        return "9999999999";
    }
    return (stack[top--]);
}

typedef enum{lpara, rpara, plus, minus, multi, div, mod, eos, operand} precedence;

int isp[10] = { 0, 19, 12, 12, 13, 13, 13, 0}; // in stack
int icp[10] = {20, 19, 12, 12, 13, 13, 13, 0}; //before stack

precedence get_token(char c)
{
    switch(c)
    {
        case '#': return eos;
        case '(': return lpara;
        case ')': return rpara;
        case '+': return plus;
        case '-': return minus;
        case '*': return multi;
        case '/': return div;
        case '%': return mod;
        default : return operand;
    }
}

void infix2Postfix()
{
    push('#');

    int i=0;
    int j=0;
    precedence temp;

    while(infix[i] != '\0')
    {
        temp = get_token(infix[i]);

        if(temp == operand)
        {
            postfix[j++] = infix[i];

        }
        else if(temp == rpara)
        {
            while(stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while(icp[temp] <= isp[get_token(stack[top])])
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    while(stack[top]!='#')
    {
        postfix[j++] = pop(0);
    }
}

int main()
{
    printf("Enter infix:\n");
    scanf("%s",&infix);

    infix2Postfix();
    printf("Post = %s",postfix);


    return 0;
}
