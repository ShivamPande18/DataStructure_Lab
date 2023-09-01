#include<stdio.h>
#define SIZE 100

char stack[SIZE];
char infix[SIZE];
char revInfix[SIZE];
char revPrefix[SIZE];
char prefix[SIZE];
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
        return '#';
    }
    return (stack[top--]);
}

typedef enum{rpara, lpara, plus, minus, multi, div, mod, eos, operand} precedence;

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

void reverseFix(int isInfix)
{
    if(isInfix==1)
    {
        int len=0;
        for(len=0;infix[len]!='\0';len++);
        len--;
        int i=0;
        while(len>-1)
        {
            revInfix[i]=infix[len];
            len--;
            i++;
        }
        revInfix[i] = '\0';
    }
    else
    {
        int len=0;
        for(len=0;revPrefix[len]!='\0';len++);
        len--;
        int i=0;
        while(len>-1)
        {
            prefix[i]=revPrefix[len];
            len--;
            i++;
        }
        prefix[i] = '\0';
    }

}

void infix2Prefix()
{
    reverseFix(1);
    push('#');

    int i=0;
    int j=0;
    precedence temp;

    while(revInfix[i] != '\0')
    {
        temp = get_token(revInfix[i]);

        if(temp == operand)
        {
            revPrefix[j++] = revInfix[i];

        }
        else if(temp == lpara)
        {
            while(stack[top] != ')')
            {
                revPrefix[j++] = pop();
            }
            pop();
        }
        else
        {
            while(icp[temp] < isp[get_token(stack[top])])
            {
                revPrefix[j++] = pop();
            }
            push(revInfix[i]);
        }
        i++;
    }

    while(stack[top]!='#')
    {
        revPrefix[j++] = pop(0);
    }

    reverseFix(0);
}

int main()
{
    printf("Enter infix:\n");
    scanf("%s",infix);
    infix2Prefix();
    printf("Pre = %s",prefix);


    return 0;
}
