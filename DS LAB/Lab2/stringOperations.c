#include <stdio.h>

int strLen(char s[100])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

void strConcat(char s1[100], char s2[100])
{
    int len1 = strLen(s1);
    int i;
    for (i = 0; s2[i] != '\0'; i++, len1++)
    {
        s1[len1] = s2[i];
    }
    s1[len1] = '\0';
}

int strCmp(char s1[100], char s2[100])
{
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }

    return 1;
}

void insertChar(char s[100], char c, int index)
{
    while (c != '\0')
    {
        char temp = s[index];
        s[index] = c;
        c = temp;
        index++;
    }
    s[index] = '\0';
}

void insertSubstr(char s[100], char sub[100], int index)
{
    int i;

    for (i = 0; sub[i] != '\0'; i++, index++)
    {
        insertChar(s, sub[i], index);
    }
}

int findSubstr(char s[100], char sub[100])
{
    int i = 0, sublen = 0;
    int cnt = 0;
    int ind = -1;

    while (s[i] != '\0')
    {
        if (s[i] == sub[0])
        {
            ind = i;
            int j = 0;
            while (sub[j] != '\0')
            {
                if (sub[j] != s[i])
                {
                    ind = -1;
                    break;
                }
                j++;
                i++;
            }
        }

        i++;
    }

    return ind;
}

void delSub(char s[100], char sub[100])
{
    int ind = findSubstr(s, sub);
    if (ind == -1)
        return;

    int sublen = strLen(sub);
    int i;
    for (i = ind; s[ind + sublen] != '\0'; i++, ind++)
    {
        s[i] = s[ind + sublen];
    }
    s[i] = '\0';
}

int main()
{
    char s1[100], s2[100];
    int ind;

    while (1==1)
    {
        int choice;

        printf("Choose:\n1) Length of String\n2) String concatenation\n3) String comparison\n4) Insert a sub string\n5) Delete a substring");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter a string");
            scanf("%s", s1);
            printf("Length of string = %d", strLen(s1));
            break;

        case 2:
            printf("Enter a string 1");
            scanf("%s", s1);
            printf("Enter a string 2");
            scanf("%s", s2);
            strConcat(s1, s2);
            printf("Concated string = %s", s1);
            break;

        case 3:
            printf("Enter a string 1");
            scanf("%s", s1);
            printf("Enter a string 2");
            scanf("%s", s2);
            printf("Comparing string = %d", strCmp(s1,s2));
            break;

        case 4:
            printf("Enter a string");
            scanf("%s", s1);
            printf("Enter a string to insert");
            scanf("%s", s2);
            printf("Enter index to insert at");
            scanf("%d", &ind);
            insertSubstr(s1, s2, ind);
            printf("New string = %s", s1);
            break;

        case 5:
            printf("Enter a string");
            scanf("%s", s1);
            printf("Enter a string to delete");
            scanf("%s", s2);
            delSub(s1, s2);
            printf("New string = %s", s1);
            break;

        default:
            break;
        }
    }

    return 0;
}
