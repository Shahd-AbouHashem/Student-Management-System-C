/*
==================================================================================================================================
	Author		: shahd mohsen mohamed maher
    Group	    : DIPLOMA 90
==================================================================================================================================
 */
#include "Student_Managment_System.h"

#include <stdio.h>
#include <stdlib.h>


link head = NULL;

void addStudent(const struct student *const ptr)
{
	link current = head;
	while(NULL != current)
	{
		if(ptr->id == current->data.id)
		{

			printf("\nStudent Already Exist!\n");
			printf("If you want to update student data use option 4 please\n\n");
			return;
		}

		current = current->next;
	}

	link add = (link)malloc(sizeof(node));
	if(NULL == add)
	{

		printf("Memory allocation failed\n\n");
		return;
	}


	add->data = *ptr;

	add->next = head;
	head = add;

	printf("Student has been Added Successfully\n\n");

}

void displayStudents(void)
{
	if(NULL == head)
	{
		printf("No Student is Registered yet\tPlease enter Student data \n\n");
		return;
	}

	printf("\n");
	link current = head;
	while(NULL != current)
	{

		printf("Student ID: %d\n", current->data.id);
		printf("Student Name: %s\n", current->data.name);
		printf("Student Age: %d\n", current->data.age);
		printf("Student GPA: %0.2f\n\n", current->data.gpa);

		current = current->next;
	}

}

void searchStudentByID(const int id)
{
	printf("\n");

	if(head == NULL)
	{
		printf("Empty,couldn't not found\n\n");
		return;
	}

	link current = head;
	while(NULL != current)
	{
		if(id == current->data.id)
		{
			printf("Student ID: %d\n", current->data.id);
			printf("Student Name: %s\n", current->data.name);
			printf("Student Age: %d\n", current->data.age);
			printf("Student GPA: %0.2f\n\n", current->data.gpa);
			return;
		}

		current = current->next;
	}

	printf("Student id Not Found");

}

void updateStudent(const int id)
{
	printf("\n");

	if(head == NULL)
	{
		printf("Empty, couldn't not found\n");
		return;
	}

	link current = head;
	while(NULL != current)
	{
		if(id == current->data.id)
		{
			printf("please Enter Student Name: ");
			scanf(" %[^\n]s", current->data.name);

			printf("please Enter Student Age: ");
			scanf(" %d", &current->data.age);

			printf("please Enter Student GPA: ");
			scanf(" %f", &current->data.gpa);

			printf("\nUpdated Successfully\n");
			return;
		}

		current = current->next;
	}

}

float calculateAverageGPA(void)
{

	printf("\n");

	if(head == NULL)
	{
		printf("Empty, couldn't not found!\n");
		return 0.0;
	}

	int numofstudents = 0;
	float GPAsum = 0.0;

	link current = head;
	while(NULL != current)
	{
		numofstudents++;
		GPAsum += current->data.gpa;

		current = current->next;
	}

	return GPAsum / numofstudents;

}

void searchHighestGPA(void)
{
	printf("\n");

	if(head == NULL)
	{
		printf("Empty, couldn't not found!\n");
		return;
	}

	link maxGPAptr = head;
	link current = head->next;
	while(NULL != current)
	{
		if(current->data.gpa > maxGPAptr->data.gpa)
			maxGPAptr = current;

		current = current->next;
	}



	printf("The Student with highest GPA is:\n");
	printf("\tStudent ID: %d\n", maxGPAptr->data.id);
	printf("\tStudent Name: %s\n", maxGPAptr->data.name);
	printf("\tStudent Age: %d\n", maxGPAptr->data.age);
	printf("\tStudent GPA: %0.2f\n\n", maxGPAptr->data.gpa);


}

void deleteStudent(int id)
{
	printf("\n");

	if(head == NULL)
	{
		printf("Empty, couldn't not found\n");
			return;
	}

	if(id == head->data.id)
	{
		link delete_node = head;
		head = head->next;
		free(delete_node);
		printf("\nStudent is Deleted Successfully\n");
		return;
	}

	link prev = head;
	link current = head;
	while(NULL != current)
	{
		if(id == current->data.id)
		{
			link delete_node = current;
			prev->next = delete_node->next;
			free(delete_node);
			printf("\nStudent is Deleted Successfully\n");
			return;
		}

		prev = current;
		current = current->next;
	}


	printf("\nDelete Failed\tStudent Not Found...\n\n");

}



