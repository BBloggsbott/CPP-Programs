//A Program to implementdoubly linked list
#include<iostream>
using namespace std;

struct node
{
	int data;
	node *pLink;
	node *sLink;
}*head=NULL;

void insert_at_begining(int data)
{
	
	node *newNode;
	newNode=new node;
	newNode->data=data;
	newNode->pLink=NULL;
	if(head!=NULL)
	{	newNode->sLink=head;
		head->pLink=newNode;
	}
	else
		newNode->sLink=NULL;
	head=newNode;
	cout<<"\nSuccessfully inserted";
}

void insert_at_end(int data)
{
	if(head==NULL)
	{
		node *newNode;
		newNode=new node;
		newNode->data=data;
		newNode->pLink=NULL;
		newNode->sLink=NULL;
		head=newNode;
	}
	else
	{
		node*temp;
		temp=new node;
		temp=head;
		while(temp->sLink!=NULL)
			temp=temp->sLink;
		node *newNode;
		newNode=new node;
		newNode->data=data;
		newNode->sLink=NULL;
		newNode->pLink=temp;
		temp->sLink=newNode;
	}
	cout<<"\nSuccessfully inserted";
}

void insert_at_pos(int pos,int data)
{
	node *temp;
	temp=new node;
	int i=1;
	temp=head;
	while(i<pos)
	{
		temp=temp->sLink;
		if(temp==NULL)
		{	cout<<"\nInvalid Location!!";
			return;
		}
		i=i+1;
	}
	node *newNode;
	newNode=new node;
	newNode->data=data;
	newNode->pLink=temp;
	newNode->sLink=temp->sLink;
	temp->sLink->pLink=newNode;
	temp->sLink=newNode;
	cout<<"\nSuccessfully inserted";
}

void delete_node(int data)
{
	if((head->sLink==NULL)&&(head->data==data))
	{
		head=NULL;
		return;
	}

	node *temp;
	temp=new node;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==data)
		{
			if(temp==head)
			{	head=temp->sLink;
				head->pLink=NULL;
			}
			else
			{
				if(temp->sLink==NULL)
					temp->pLink->sLink=NULL;
				else
				{	temp->pLink->sLink=temp->sLink;
					temp->sLink->pLink=temp->pLink;
				}
			}
			delete temp;
			cout<<"\nSuccessfully deleted";
			return;
		}
		temp=temp->sLink;
	}
	
	cout<<"\nData Not Found!!";
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
		temp=temp->sLink;
		count=count+1;
	}
	
	cout<<"\nInvalid Location";
	return -1;
}
int count_node()
{
	node *temp;
	temp=new node;
	temp=head;
	int count=0;
	while(temp!=NULL)
	{
		temp=temp->sLink;
		count=count+1;
	}

	return count;
}

void display()
{
	if(head==NULL)
		cout<<"\nEmpty List!!";

	node *temp,*temp1;
	temp=new node;
	temp1=new node;
	temp=head;
	temp1=head;
	cout<<"\nDisplay in forward direction: ";
	while(temp!=NULL)
	{
		cout<<temp->data;
		if(temp->sLink!=NULL)
		{	cout<<"->";
			temp1=temp1->sLink;
		}
		temp=temp->sLink;
	}

	cout<<"\nDisplay in backward direction: ";
	while(temp1!=NULL)
	{
		cout<<temp1->data;
		if(temp1->pLink!=NULL)
			cout<<"->";
		temp1=temp1->pLink;
	}
}


int main()
{
	int choice,data,pos,count;
	
	do
	{
		cout<<"\n\nMenu\n1.Insert at Begining\n2.Insert at End\n3.Insert at Position\n4.Delete Node\n5.Retrieve Data\n6.Count Nodes\n7.Display\n8.Exit\nEnter Choice: ";
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
				cout<<"\nEnter position of insertion: ";
				cin>>pos;
				insert_at_pos(pos,data);
				break;
			case 4:	cout<<"\nEnter data to delete: ";
				cin>>data;
				delete_node(data);
				break;
			case 5:	cout<<"\nEnter position to retrieve data: ";
				cin>>pos;
				data=retrieve_data(pos);
				if(data!=-1)
					cout<<"\nRetireved data: "<<data;
				break;
			case 6:	count=count_node();
				cout<<"\nNumber of Nodes: "<<count;
				break;
			case 7:	display();
				break;
			case 8:	break;
			default: cout<<"\nInvalid Input!!";
		}
	}while(choice!=8);
	
	cout<<"\n\n";
	return 0;
}
