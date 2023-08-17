#include <stdio.h>

#define MAX_STUDENTS 100

struct student
{
    char name[50];
    int roll_no;
    char grade;
};

void readStudentData(struct student students[], int count);
void displayStudentData(struct student students[], int count);
void sortStudents(struct student students[], int count);

int main()
{
    struct student students[MAX_STUDENTS];
    int num_students;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    readStudentData(students, num_students);

    printf("\nStudent Information:\n");
    displayStudentData(students, num_students);

    sortStudents(students, num_students);

    printf("\nStudent Information (Sorted by Roll Number):\n");
    displayStudentData(students, num_students);

    return 0;
}

void readStudentData(struct student students[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll_no);
        printf("Grade: ");
        scanf(" %c", &students[i].grade);
    }
}

void displayStudentData(struct student students[], int count)
{
    
    for (int i = 0; i < count; i++)
    {
        printf("%s %d %c\n", students[i].name, students[i].roll_no, students[i].grade);
    }
}

void sortStudents(struct student students[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (students[j].roll_no > students[j + 1].roll_no)
            {
                struct student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
