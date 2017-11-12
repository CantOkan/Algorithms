#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
struct stack
{
	int stack[SIZE];
	int top;
};typedef struct stack STACK;
STACK s;
void push(int);
void pop();
void display();

int main(int argc, char *argv[]) {
	s.top=-1;
	
	push(5);
	push(6);
	push(7);
	push(8);
	pop();
	display();
}

void push(int num)
{
	if(s.top==(SIZE-1))
	{
		printf("Size is full");
		
	}
	s.top=s.top+1;
	s.stack[s.top]=num;
}
void pop()
{
	if(s.top==-1)
	{
		printf("it is empty");
	}
	else
	{
		int num=s.stack[s.top];
		s.top=s.top-1;
		printf("it is popped elemnt:%d \n",num);
	}
	
}
void display()
{
	int i;
	if(s.top==-1)
	printf("it is empty");
	else{
		for(i=0; i<(s.top+1); i++)
		{
			printf("%d",s.stack[i]);
			printf("\n");
		}
		
	}
}
