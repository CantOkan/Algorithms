#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node *head=NULL;
int add(int s)
{
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=s;
		head->next=NULL;
	}
	else
	{
		struct node *temp=head;
		struct node *add=(struct node*)malloc(sizeof(struct node));
		add->data=s;
		add->next=NULL;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=add;
	}
}
void pop()
{
	struct node *delete=head;
	while(delete->next->next!=NULL)
	{
		delete=delete->next;
	}
	free(delete->next);
	delete->next=NULL;
}
void display()
{
	struct node *display=head;
	
	while(display!=NULL)
	{
		printf("%d ",display->data);
		display=display->next;
	}
}
int main(int argc, char *argv[]) {
	add(5);
	add(6);
	add(7);
	pop();
	display();
	
	return 0;
}
