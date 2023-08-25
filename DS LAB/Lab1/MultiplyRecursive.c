#include <stdio.h>

int multiply(int a, int b, int ind = 1)
{
    if(ind == a) return b;

    return b + multiply(a,b,ind+1);
}


int main()
{
    int a,b;

    printf("Enter a:\n");
    scanf("%d", &a);

    printf("Enter b:\n");
    scanf("%d", &b);

    int res;
    if(a<=b) res = multiply(a,b);
    else res = multiply(b,a);

    printf("%d",res);

    return 0;
}
