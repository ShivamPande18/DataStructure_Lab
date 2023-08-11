#include <stdio.h>
struct student {
   char name[50];
   int age;
};

void display(struct student s1[3])
{
    for(int i=0;i<2;i++)
    {
        printf("\nDisplaying information\n");
        printf("Name: %s", s1[i].name);
        printf("\nAge: %d", s1[i].age);
    }
}

int main() {
   struct student s1[2];

   for(int i=0; i<2; i++)
   {
        printf("Enter name: ");

        scanf("%[^\n]%*c", s1[i].name);
        fflush(stdin);
        printf("Enter age: ");
        scanf("%d", &s1[i].age);
        fflush(stdin);


   }


    display(s1);


   return 0;
}
