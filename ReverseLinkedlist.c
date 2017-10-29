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

void display()
{
	struct node *display=head;
	
	while(display!=NULL)
	{
		printf("%d->",display->data);
		display=display->next;
	}
}
void reverse()
{
	struct node *prev   = NULL;
    struct node *current = head;
    struct node *next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    head=prev;
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d->", temp->data);    
        temp = temp->next;  
    }
	
}
int main(int argc, char *argv[]) {
	add(5);
	add(6);
	add(7);
	display();
	printf("\n");
	reverse();
	return 0;
}
