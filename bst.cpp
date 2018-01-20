//A Program to implement a binary search tree
#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
}*root;
	
void insertBST(int data)
{
	node *newNode;
	newNode=new node;
	newNode->data=data;
	newNode->right=NULL;
	newNode->left=NULL;
	if(root==NULL)
	{
		root=newNode;
	}
	else
	{
		node *pWalk,*parent;
		pWalk=new node;
		parent=new node;
		pWalk=root;
		while(pWalk!=NULL)
		{	parent=pWalk;
			if(newNode->data<pWalk->data)
				pWalk=pWalk->left;
			else
				pWalk=pWalk->right;
		}
	
		if(newNode->data<parent->data)
			parent->left=newNode;
		else
			parent->right=newNode;
	}
}
void deleteBST(node *root,int data)
{
	if(root==NULL)
	{
		cout<<"\nNode not found!!";
		return;
	}
	if(data<root->data)
		deleteBST(root->left,data);
	else if(data>root->data)
		deleteBST(root->right,data);
	else
	{
		node *dltptr;
		dltptr=new node;
		if(root->left==NULL && root->right==NULL)
			root==NULL;
		if(root->left==NULL)
		{
			dltptr=root;
			root=dltptr->right;
			delete dltptr;
		}
		else if(root->right==NULL)
		{
			dltptr=root;
			root=root->left;
			delete dltptr;
		}
		else
		{
			dltptr=root->left;
			int temp= dltptr->data;
			while(dltptr->right!=NULL)
				dltptr=dltptr->right;
			deleteBST(root->left,dltptr->data);
			root->data=temp;
		}
	}
}

void preOrder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(node *root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void postOrder(node *root)
{
	if(root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}

int main()
{
	int data;
	int choice;
	do
	{
		cout<<"\nMenu\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:	cout<<"\nEnter new data: ";
				cin>>data;
				insertBST(data);
				break;
			case 2:	cout<<"\nEnter data to delete: ";
				cin>>data;
				deleteBST(root,data);
				break;
			case 3:	cout<<"\nPreOrder: ";
				preOrder(root);
				cout<<"\nInOrder: ";
				inOrder(root);
				cout<<"\nPostOrder: ";
				postOrder(root);
				break;
			case 4: break;
			default:	cout<<"\nEnter a valid option!!!";
					break;
		}
	}while(choice!=4);
	cout<<"\n\n";
	return 0;
}
