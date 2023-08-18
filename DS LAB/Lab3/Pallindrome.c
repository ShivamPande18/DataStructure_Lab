#include<stdio.h>
#define MAX 100

int top = -1;
char stack[MAX];

void AddStringToStack(char s[100])
{
    top = 0;

    while(s[top]!='\0' && top < MAX-1)
    {
        stack[top] = s[top];
        top++;
    }

    stack[top] = '\0';
}

int main()
{
    char s[100];
    int flag=1;
    printf("Enter string to check:\n");
    scanf("%s",s);

    AddStringToStack(s);

    int i=0;
    top--;
    while(top>=0)
    {
        printf("%c %c\n",stack[top],s[i]);
        if(stack[top] != s[i])
        {
            printf("Not a Pallindrome\n");
            flag=0;
            break;
        }
        i++;
        top--;
    }

    if(flag==1) printf("Word is a pallindrome\n");


    return 0;
}
