#include <stdio.h>
#include <string.h>

struct Student 
{
    int roll;
    char name[50];
    float marks;
};

// Functions declaration
void addStudent(struct Student s[], int *totalStudents);
void viewStudent(struct Student s[], int totalStudents);
void searchStudent(struct Student s[], int totalStudents);
void updateStudent(struct Student s[], int totalStudents);
void deleteStudent(struct Student s[], int *totalStudents);
void saveStudents(struct Student s[], int totalStudents);
int loadStudents(struct Student s[]);

// 1. Function to add student data
void addStudent(struct Student s[], int *totalStudents)
{
    printf("\nEnter Roll no. : ");
    scanf("%d", &s[*totalStudents].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]s", s[*totalStudents].name); 

    printf("Enter Marks: ");
    scanf("%f", &s[*totalStudents].marks);

    (*totalStudents)++;
    saveStudents(s, *totalStudents);

    printf("\nStudent Added Successfully \n");
}

// 2. Function to view all student records
void viewStudent(struct Student s[], int totalStudents)
{
    if (totalStudents == 0)
    {
        printf("\nNo Student Found !!\n");
    }
    else
    {
        printf("\n=== STUDENTS RECORD ===\n");
        for (int i = 0; i < totalStudents; i++)
        {
            printf("\nRoll No : %d\n", s[i].roll);
            printf("Name    : %s\n", s[i].name);
            printf("Marks   : %.2f\n", s[i].marks);
        }
    }
}

// 3. Function to search a specific student
void searchStudent(struct Student s[], int totalStudents)
{
    int searchroll;
    int found = 0;

    printf("\nEnter Roll no. to search: ");
    scanf("%d", &searchroll);

    for (int i = 0; i < totalStudents; i++)
    {
        if (s[i].roll == searchroll)
        {
            printf("\nStudent Found !!\n");
            printf("Roll no. : %d\n", s[i].roll);
            printf("Name     : %s\n", s[i].name);
            printf("Marks    : %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("\nStudent not found \n");
    }
}

// 4. Function to update student record
void updateStudent(struct Student s[], int totalStudents)
{
    int searchroll;
    int found = 0;

    printf("\nEnter Roll no. to search: ");
    scanf("%d", &searchroll);

    for (int i = 0; i < totalStudents; i++)
    {
        if (s[i].roll == searchroll)
        {
            printf("\nStudent Found !!\n");
            
            printf("\nEnter New Name: ");
            scanf(" %[^\n]s", s[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            printf("\nRecords updated successfully\n");
            saveStudents(s, totalStudents);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("\nStudent Not Found !! \n");
    }
}

// 5. Function to delete student record
void deleteStudent(struct Student s[], int *totalStudents)
{
    int searchroll;
    int found = 0;

    printf("\nEnter Roll no. to Delete: ");
    scanf("%d", &searchroll);

    for (int i = 0; i < *totalStudents; i++)
    {
        if (s[i].roll == searchroll)
        {
            found = 1;
            // Shifting elements to delete the student
            for (int j = i; j < *totalStudents - 1; j++)
            {
                s[j] = s[j + 1];
            }
            (*totalStudents)--;
            saveStudents(s, *totalStudents);
            printf("\nStudent Record Deleted\n");
            break;
        }
    }
    if (found == 0)
    {
        printf("\nStudent Not Found !!\n");
    }
}

// 6. Function to save data to file
void saveStudents(struct Student s[], int totalStudents)
{
    FILE *fp;
    fp = fopen("students.data", "wb");

    if (fp == NULL)
    {
        printf("File Error");
        return;
    }

    fwrite(&totalStudents, sizeof(int), 1, fp);
    fwrite(s, sizeof(struct Student), totalStudents, fp);

    fclose(fp);
}

// 7. Function to load data from file
int loadStudents(struct Student s[])
{
    FILE *fp;
    int totalStudents = 0;

    fp = fopen("students.data", "rb");

    if (fp == NULL)
    {
        return 0; 
    }

    fread(&totalStudents, sizeof(int), 1, fp);
    fread(s, sizeof(struct Student), totalStudents, fp);

    fclose(fp);
    return totalStudents;
}


int main()
{
    struct Student s[100];
    int totalStudents = 0;
    
    totalStudents = loadStudents(s);
    
    int choice;

    while (1)
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search student\n");
        printf("4. Update student\n");
        printf("5. Delete student\n");
        printf("6. Exit\n");
        
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(s, &totalStudents); 
                break;
            case 2:
                viewStudent(s, totalStudents);  
                break;
            case 3:
                searchStudent(s, totalStudents);
                break;
            case 4:
                updateStudent(s, totalStudents);
                break;
            case 5:
                deleteStudent(s, &totalStudents); 
                break;
            case 6:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}

