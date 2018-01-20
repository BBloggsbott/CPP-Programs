////A Program to convert a general tree to a binary tree
#include<iostream>
using namespace std;



struct node_tree
{
	char data;
	node_tree *right;
	node_tree *left;
};

struct node_stack
{
	node_tree *newNode;
	int lvl;
	node_stack *next;
};

void push(node_stack *top,int lvl,node_tree *node)
{
	node_stack *Node;
	Node=new node_stack;
	Node->newNode=node;
	Node->lvl=lvl;
	Node->next=top;
	top=Node;
}

node_stack * pop(node_stack *top)
{
	node_stack *temp;
	temp=new node_stack;
	temp=top;
	top=top->next;
	temp->next=NULL;
	return temp;
}

node_stack * peek(node_stack *top)
{
	return  top;
}

void preOrder(node_tree *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(node_tree *root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void postOrder(node_tree *root)
{
	if(root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}

void display(node_tree *node)
{
	cout<<"\nPreOrder: ";
	preOrder(node);
	cout<<"\nInOrder: ";
	inOrder(node);
	cout<<"\nPostOrder: ";
	postOrder(node);
}

void convert_tree()
{
	node_tree *head,*Node;
	head=new node_tree;	Node=new node_tree;
	head->right=NULL;	Node->right=NULL;
	head->left=NULL;	Node->left=NULL;
	node_stack *top,*pred;
	top=new node_stack;	pred=new node_stack;
	int lvl;char data;
	push(top,0,head);
	do
	{
		cout<<"\nEnter level(Enter negative level or 0 to terminate): ";
		cin>>lvl;
		if(lvl>0)
		{
			cout<<"Enter data: ";
			cin>>data;
			Node->data=data;
			pred=peek(top);
			if(lvl>pred->lvl)
				pred->newNode->left=Node;
			else
			{
				while(pred->lvl>lvl)
				{
					pop(top);
					pred=peek(top);
				}
				if(pred->lvl<lvl)
				{
					cout<<"\nError in input. Mixed Level numbers!!!";
					return;
				}
				pred->newNode->right=Node;
				pop(top);
			}
			push(top,lvl,Node);
		}
	}while(lvl>0);
	display(head->right);
}


int main()
{
	cout<<"\n\n\t\tGeneral tree to Binary tree";
	cout<<"\n\t\t------- ---- -- ------ ----";
	convert_tree();
	cout<<"\n\n";
	return 0;
}
