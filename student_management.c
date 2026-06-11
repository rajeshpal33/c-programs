#include<stdio.h>

typedef struct student_management{
	int roll;
	char name[50];
	float marks;
}student;

int main(){
	student s;
	printf("Enter Roll No. :");
	scanf("%d", &s.roll);

	printf("Enter Name : ");
	scanf("%s", s.name);

	printf("Enter Marks : ");
	scanf("%f", &s.marks);

	printf("\n------STUDENT DETAILS------");
	printf("\n");
	printf("Roll Number : %d\n", s.roll);
	printf("Name : %s\n", s.name);
	printf("Marks : %.2f\n", s.marks);

	return 0;
}
