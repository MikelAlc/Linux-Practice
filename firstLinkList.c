#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node* next;
};

typedef struct node node_t;

void printlist(node_t *head)
{
	node_t* temp= head;
	while(temp != NULL)
	{
		printf("%d - ", temp -> value);
		temp = temp -> next;
	}
	printf("\n");
}

//Creates nodes
node_t* newNode(int val)
{
	node_t *result = malloc(sizeof(node_t));
	result -> value = val;
	result -> next = NULL;
	return result;
	
}

//Adds nodes at the front of list
node_t* newHead(node_t **head, int val)
{
	node_t *front = newNode(val);
	front->next=*head;
	*head=front;
	return front;
	
}

//Adds nodes at the back of list
//Returns the back of list, maybe should change to return the head of new list
node_t* newTail(node_t* head, int val)
{
	node_t* back= newNode(val);
	node_t* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=back;
	return back;
	
}

int hasVal(node_t* head, int val)
{
	node_t* temp= head;
	while(temp != NULL)
	{
		
		if(temp->value==val)
		{
			printf("Countains val %d\n", val);
			return 1;
		}
		temp = temp -> next;
	}
	printf("Does not countains val %d", val);
	printf("\n");
	return 0;
}

int main()
{
	node_t *head;
	node_t *temp;

	temp=newNode(1);
	head=temp;
	temp=newNode(2);
	temp->next=head;
	head=temp;
	temp=newNode(3);
	temp->next=head;
	head=temp;
	newHead(&head, 5);
	newTail(head,0);
	
	
	printlist(head);
	int count=0;
	for (int i=0;i<10; i++)
	{
		
		count+=hasVal(head,i);
	}
	printf("Amound of vals contained: %d\n",count);
	return 0;
}