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



//    AddToStackRev(1234);

    int res=0;

    while(top>=0)
    {
        printf("%d ", stack[top]);
        top--;
    }


    return 0;
}

