#include<stdio.h>

int isPrime(int n)
{
    if(n<2) return 0;

    int factCnt = 0;

    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0) factCnt++;

        if(factCnt>1) return 0;
    }
    return 1;
}

int main()
{
    int low,high;
    printf("Enter the lower range:\n ");
    scanf("%d",&low);

    printf("Enter the higher range:\n ");
    scanf("%d",&high);

    if(low>high)
    {
        int temp = low;
        low = high;
        high = temp;
    }

    printf("The prime numbers in the range are:\n");

    for(int i=low; i<high+1; i++)
    {
        if(isPrime(i) == 1)
        {
            printf("%d ",i);
        }
    }

    return 0;
}
