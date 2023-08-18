#include<stdio.h>
#define SIZE 100

char stack[SIZE];

int top =-1;

void Push(char c)
{
    top++;
    if(top>=SIZE)
    {
        printf("Stack out of bound");
        return;
    }

    stack[top] = c;
}

char Pop()
{
    return (stack[top--]);
}

int main()
{
    char s[100];

    printf("Enter a string:\n");
    scanf("%s",s);



    int i=0;

    while(s[i]!='\0')
    {
        char c = s[i];

        printf("%c\n",c);

        switch(c)
        {
            case '{':
            case '(':
            case '[':
            case '<':
                Push(c);
                break;

            case '}':
                if(top == -1)
                {
                    top = -2;
                    break;
                }
                if(stack[top] == '{')
                {

                    Pop();
                    break;
                }
            case ')':
                if(top == -1)
                {
                    top = -2;
                    break;
                }
                if(stack[top] == '(')
                {
                    Pop();
                    break;
                }
            case ']':
                if(top == -1)
                {
                    top = -2;
                    break;
                }
                if(stack[top] == '[')
                {
                    Pop();
                    break;
                }
            case '>':
                if(top == -1)
                {
                    top = -2;
                    break;
                }
                if(stack[top] == '<')
                {
                    Pop();
                    break;
                }
        }
        i++;
    }

    if(top==-1) printf("Matching");
    else printf("Not Matching");

    return 0;
}
