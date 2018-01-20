//A Program to implement Linked list 
#include<iostream>
using namespace std;


struct node
{
	int data;
	node *link;
}*head;

void insert_at_begining(int data)
{	
	node *newNode=new node;
	newNode->data=data;
	newNode->link=head;
	head=newNode;
}

void insert_at_end(int data)
{
	node *newNode;
	newNode=new node;
	
	if(head==NULL)
	{	
		newNode->data=data;
		newNode->link=NULL;
		head=newNode;
	}

	else
	{
		node *temp;
		temp= new node;
		temp=head;
		while(temp->link!=NULL)
			{
			temp=temp->link;
			}
		newNode->data=data;
		newNode->link=NULL;
		temp->link=newNode;
	}
	
}

void insert_at_pos(int pos,int data)
{
	node *temp;
	temp= new node;
	head=temp;
	for(int i=1;i<pos;i++)
	{
		temp=temp->link;
		if(temp==NULL)
		{	cout<<"\nInvalid Location!!";
			return;
		}
	}
	node *newNode;
	newNode=new node;
	newNode->data=data;
	newNode->link=temp->link;
	temp->link=newNode;
}

void delete_node(int data)
{
	if((head->link==NULL)&&(head->data==data))
	{		
	head=NULL;
	}
	node *temp,*p;
	temp=new node;
	p=new node;
	temp=head;
	p=temp;
	while(temp!=NULL)
	{	
		if(temp->data==data)
		{	if(temp==head)
				head=temp->link;
			else
				p->link=temp->link;
			delete temp;
			return;	
		}
		else
		{
			p=temp;
			temp=temp->link;
		}
	}
	cout<<"\nData not found!!";
}

int retrieve_data(int pos)
{
	node *temp;
	temp=new node;
	temp=head;
	int count=1;
	while(temp!=NULL)
	{
		if(count==pos)	
			return temp->data;
		temp=temp->link;
		count=count+1;
	}
	cout<<"\nInvalid Location!!";
	return -1;
}

int count_node()
{
	node *temp;
	temp= new node;
	temp=head;	
	int count=0;
	while(temp!=NULL)
	{
		temp=temp->link;
		count=count+1;
	}
	return count;
}

int main()
{
	int choice,data,pos,count;
	//node *head;
	//head=NULL;
	do
	{
		cout<<"\nMenu\n1.Insert at Begining\n2.Insert at end\n3.Insert at specific position\n4.Delete Node\n5.Retrieve data\n6.Count Node\n7.Exit\nEnter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:	cout<<"\nEnter new data: ";
				cin>>data;
				insert_at_begining(data);
				break;
			case 2:	cout<<"\nEnter new data: ";
				cin>>data;
				insert_at_end(data);
				break;
			case 3:	cout<<"\nEnter new data: ";
				cin>>data;
				cout<<"Enter position for insertion: ";
				cin>>pos;
				insert_at_pos(pos,data);
				break;
			case 4:	cout<<"\nEnter data to delete: ";
				cin>>data;
				delete_node(data);
				break;
			case 5:	cout<<"\nEnter position of node to retireve: ";
				cin>>pos;
				data=retrieve_data(pos);
				if(data!=-1)
					cout<<"\nRetrieved data: "<<data;
				break;
			case 6:	count=count_node();
				cout<<"\nTotal Number of nodes: "<<count;
				break;
			case 7:	break;
			default:cout<<"\nEnter valid choice: ";
		}
	}while(choice!=7);
	cout<<"\n\n";
	return 0;
}
