#include<stdio.h>
#include<stdlib.h>
void insert(int);
void search(int);

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

void preorder( node*);
void inorder(node*);
void postorder(node*);

node* root=NULL;
node* current;
node* parent;

int main()
{
	while(1)
	{
		printf("\n1.insert in tree");
		printf("\n2.search in tree");
		printf("\n3.preorder traversal");
		printf("\n4.postorder traversal");
		printf("\n5.inoder traversal");
		printf("\n6.exit");
		int ch,num,value;
		printf("\n\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			        printf(" \n Enter the number to insert :");
			        scanf("%d",&num);
			        insert(num);
			break;
			case 2:
			       printf(" \n Enter the number to search :");
			       scanf("%d",&value); 
			       search(value);
			break;
			case 3:current=root;
			       preorder(current);
			break;
			case 4 :current=root;
			        postorder(current);
			break;
			case 5 :current=root;
			        inorder(current);
			break;
			case 6 : exit(0);
			break;
			default : printf("\n WRONG CHOICE ");
		}
	}
}


void insert(int num)
{
	node* temp;
	
	temp=(node*)malloc(sizeof(node));
	temp->data=num;
	if(root==NULL)
	{
		temp->right==NULL;
		temp->left=NULL;
		root=temp;
	}
	else
	{
		current=root;
		while(1)
		{
			if(num>current->data)
			{
				parent=current;
				current=current->right;
				if(current==NULL)
				{
					parent->right=temp;
					temp->right=NULL;
					temp->left=NULL;
					
					break;
				}
			}
			else
			{
				parent=current;
				current=current->left;
					if(current==NULL)
				{
					parent->left=temp;
					temp->right=NULL;
					temp->left=NULL;
					
					break;
				}
			}
		}
	}
	
}

void search(int num)
{
	current=root;
	int c=1;
	while( current != NULL)
	{
		parent=current;
		if(num==current->data)
		{
			printf(" \n number is found \n ");
			c=0;
			break;
		}
		else if(num>current->data)
		{
			current=current->right;
		}
		else 
		{
			current=current->left;
		}
	}
	if( c==1)
	{
		printf(" \n NUMBER NOT FOUND \n");
	}
}

void preorder(node* current )
{
   if(current==NULL)
	{
		return;
	}
	printf("%d ",current->data);
	inorder(current->left);
	inorder(current->right);
	
}

void postorder(node* current)
{
	if(current==NULL)
	{
		return;
	}
	inorder(current->left);
	inorder(current->right);
	printf("%d ",current->data);
	
}

void inorder(node* current)
{
	if(current==NULL)
	{
		return;
	}
	inorder(current->left);
	printf("%d ",current->data);
	inorder(current->right);

}


