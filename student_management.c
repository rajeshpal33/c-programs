#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

int main()
{
    struct Student s[100];
    int totalStudents = 0;
    int choice, i;

    while(1)
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter Roll Number: ");
                scanf("%d", &s[totalStudents].roll);

                printf("Enter Name: ");
                scanf("%s", s[totalStudents].name);

                printf("Enter Marks: ");
                scanf("%f", &s[totalStudents].marks);

                totalStudents++;

                printf("Student Added Successfully!\n");
                break;

            case 2:
                if(totalStudents == 0)
                {
                    printf("\nNo Students Found!\n");
                }
                else
                {
                    printf("\n===== STUDENT RECORDS =====\n");

                    for(i = 0; i < totalStudents; i++)
                    {
                        printf("\nRoll No : %d\n", s[i].roll);
                        printf("Name    : %s\n", s[i].name);
                        printf("Marks   : %.2f\n", s[i].marks);
                    }
                }
                break;

            case 3:
                printf("\nExiting Program...\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}
