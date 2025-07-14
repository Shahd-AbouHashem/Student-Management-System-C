/*
==================================================================================================================================
Author		: shahd mohsen mohamed maher
Group	    : DIPLOMA 90
==================================================================================================================================
 */
#include <stdio.h>

#include "Student_Managment_System.h"
#include "Student_Managment_System.h"

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int option;
	struct student user_option;
	int id;

	for(;;)
	{
		printf("Welcome to our Student Management System \n");
		printf("1- Add Student.\n");
		printf("2- Display Students.\n");
		printf("3- Search Student with ID.\n");
		printf("4- Update Student with ID.\n");
		printf("5- Delete Student with ID.\n");
		printf("6- Calculate Average GPA.\n");
		printf("7- Highest GPA Student data.\n");
		printf("8- Exit System.\n");
		printf("Please Enter wanted option Number from Above:\t");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				printf("PLease Enter Student ID: ");
				scanf(" %d", &user_option.id);

				printf("Please Enter Student Name: ");
				scanf(" %[^\n]s", user_option.name);

				printf("Please Enter Student Age: ");
				scanf(" %d", &user_option.age);

				printf("Please Enter Student GPA: ");
				scanf(" %f", &user_option.gpa);

				addStudent(&user_option);
				break;

			case 2:
				displayStudents();
				break;

			case 3:
				printf("Please Enter Student ID: ");
				scanf(" %d", &id);
				searchStudentByID(id);
				break;

			case 4:
				printf("Please Enter Student ID: ");
				scanf(" %d", &id);
				updateStudent(id);
				break;

			case 5:
				printf("Please Enter Student ID: ");
				scanf(" %d", &id);
				 deleteStudent(id);
				break;

			case 6:
				printf("The Average GPA of all student: %0.2f\n\n", calculateAverageGPA());
				break;

			case 7:
				searchHighestGPA();
				break;
			default:
				printf("Student Management System\n");
		}
	}

	return 0;
}

