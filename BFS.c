#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
struct node *newNode(int num)
{
	struct node *app;
	app=(struct node*)malloc(sizeof(struct node));
	app->data=num;
	app->left=NULL;
	app->right=NULL;
	if(root==NULL)
	{
		root=app;
	}
	return app;
}
void inorder(struct node *display)
{
	if(display !=NULL)
	{
		inorder(display->left);
		printf("%d-",display->data);
		inorder(display->right);
	}
}
struct node *insert(struct node* node,int num)
{
	if(node==NULL)
	{
		return newNode(num);
	}
	if(num<node->data)
	{
		node->left=insert(node->left,num);
	}
	else if(num>node->data)
	{
		node->right=insert(node->right,num);
	}
}

int main(int argc, char *argv[]) {
	int s;
	int number;
do{
	  printf("\n 1.add number \n 2.extract number \n 3.display \n 4.done  \n");
	  scanf("%d",&s);
	  switch(s)
	  {
	  	case 1:printf("enter number : ");
	  	scanf("%d",&number);
	  	insert(root,number);
	  	break;
	  	case 2:printf("number was deleted \n");
	  	break;
       	case 3:inorder(root);
	  	break;
	  }
		
	}while(s!=4);
	return 0;
}
