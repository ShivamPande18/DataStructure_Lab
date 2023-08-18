#include<stdio.h>
#include<math.h>
#define MAX 100

int top = -1;
int stack[MAX];

void AddToStack(int n)
{
    top++;
    if(top<MAX)
    {
        stack[top] = n;
    }
    else
    {
        printf("Stack Out Of Bound");
    }
}

int main()
{
    int n,base;

    printf("Enter a number\n");
    scanf("%d",&n);

    printf("Enter the base\n");
    scanf("%d",&base);

    while(n!=0)
    {
        AddToStack(n%base);
        n/=base;
    }


    int res=0;

    while(top>=0)
    {
        int pop = stack[top];

        if(pop>=10)
            printf("%c",pop+55);
        else printf("%d", pop);
        top--;
    }


    return 0;
}

