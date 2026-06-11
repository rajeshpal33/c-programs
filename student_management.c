#include<stdio.h>

typedef struct student_management{
	int roll;
	char name[50];
	float marks;
}student;

int main(){

	int choice, i;
	printf("How many students : ");
	scanf("%d", &n);

	student s[n];
	for(int i=0;i<n;i++){
		printf("Enter Roll No. :");
		scanf("%d", &s[i].roll);

		printf("Enter Name : ");
		scanf("%s", s[i].name);

		printf("Enter Marks : ");
		scanf("%f", &s[i].marks);
}

	for(int i=0;i<n;i++){
		printf("\n------STUDENT DETAILS------");
		printf("\n");
		printf("\nRoll Number : %d\n", s[i].roll);
		printf("\nName : %s\n", s[i].name);
		printf("\nMarks : %.2f\n", s[i].marks);

		return 0;
}

}
