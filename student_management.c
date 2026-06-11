#include<stdio.h>

struct student{
	int roll;
	char name[50];
	float marks;
}

int main(){
	int i,n;
	printf("How many students: ");
	scanf("%d", &n);

	struct student s[n];
	for(int i=0;i<n;i++){
		printf("Enter Roll no.: ");
		scanf("%d", &s[i].roll);

		printf("Enter Name: ");
		scanf("%s", s[i].name);

		printf("Enter Marks: ");
		scanf("%f", &marks);
}


	printf("\n--------STUDENT DETAILS--------");
	for(int i=0;i<n;i++){
		printf("Student %d\n", i+1);
		printf("Roll No.: %d\n", s[i].roll);
		printf("Name: %s\n", s[i].name);
		printf("Marks: %f\n", s[i].marks);
}
return 0;
}

