#include<stdio.h>
#define SIZE 100
#define TOP_LEN 4

char stack[SIZE * TOP_LEN];

int top[TOP_LEN];

void InitTop()
{
    for(int i=0; i<TOP_LEN; i++)
    {
        top[i] = -1 + (SIZE*i);
    }
}

void Push(int stackInd, int n)
{
    top[stackInd]++;
    if(top[stackInd] >= SIZE * (stackInd+1))
    {
        printf("Stack out of bound");
        return;
    }

    stack[top[stackInd]] = n;
}

char Pop(int stackInd)
{
    if(top[stackInd]<= -1 + (SIZE*stackInd))
    {
        printf("Stack empty");
        return "9999999999";
    }
    return (stack[top[stackInd]--]);
}

void Disp(int stackInd)
{
    int i = top[stackInd];

    while(i> -1 + (SIZE*stackInd))
    {
        printf("%d ", stack[i]);
        i--;
    }
    printf("\n");
}

int main()
{
    InitTop();
    for(int i=0; i<TOP_LEN;i++)
    {
        printf("top = %d \n",top[i]);
    }

  //Sample inputs need to change it to scanf statements
    Push(0,1);
    Push(0,2);
    Push(1,3);
    Push(1,4);
    Push(2,5);
    Push(2,6);
    Push(3,7);
    Push(3,8);

    Disp(0);
    Disp(1);
    Disp(2);
    Disp(3);
    return 0;
}
