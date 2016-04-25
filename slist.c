#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node {
	int info;
	struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x== NULL)
	{
		printf("Outof memory\n");
		exit(0);
	}
	return x;
}
NODE insert_front(int item,NODE first)
{
	NODE temp;
	temp = getnode();
	temp -> info = item;
	temp -> next = first;
	return temp;
}
void display(NODE first)
{
	NODE temp;
	if(first == NULL)
	{
		printf("List is empty \n");
		return;
	}
	printf("The contents of single linked list is \n");
	temp = first;
	while(temp != NULL)
	{
		printf("%d ",temp -> info);
		temp = temp -> next;
	}
	printf("\n");
}
NODE reverse(NODE first)
{
	NODE temp;
	NODE current;
	current = NULL;
	while(first != NULL)
	{
		temp = first;
		first = first -> next;
	
		temp -> next = current;
		current = temp;
	}
	return current;
}
NODE insert_end(int item,NODE first)
{
	NODE temp;
	NODE current;
	temp = getnode();
	temp -> info = item;
	temp -> next = NULL;
	if(first == NULL)
		return temp;
	current = first;
	while(current -> next != NULL)
	{
		current = current -> next;
	}
	current -> next = temp;
	return first;
}
void main()
{
	NODE first = NULL;
	int choice,item;

	for(;;)
	{
		printf("1: Insert Front \n");
		printf("2: Insert  at End \n");
 		printf("3: Delete Front \n");
		printf("4: Delete End \n");

		printf("5: Display \n");
		printf("6: Reverse \n");
		printf("7: Quit \n");
		printf("Enter the choice \n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter the item to be inserted \n");
				scanf("%d",&item);
			
				first = insert_front(item,first);
				break;
			case 2:
				printf("Enter the item to be inserted at end \n");
				scanf("%d",&item);
				first = insert_end(item,first);
				break;
			case 5:
				display(first);
				break;
			case 6:
				first = reverse(first);
				break;
			
			default:
				exit(0);
		}
	}
}
				
