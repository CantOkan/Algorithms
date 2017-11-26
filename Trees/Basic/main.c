#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
struct node *insert(struct node *node,int num)
{
	if(node==NULL)
	{
		node=(struct node*)malloc(sizeof(struct node));
		node->data=num;
		node->left=NULL;
		node->right=NULL;
		return node;
	}
	else
	{
		if(num>node->data)
		{
			node->right=insert(node->right,num);
		}
		else{
			node->left=insert(node->left,num);
		}
		
	}
}
void inorder(struct node *temporary)
{
	if(temporary!=NULL)
	{
		inorder(temporary->left);
		printf("%d\n",temporary->data);
		inorder(temporary->right);
	}
}
int main(int argc, char *argv[]) 
{
	
	root=insert(root,5);
	root=insert(root,6);
	root=insert(root,4);
	inorder(root);
	return 0;
}
