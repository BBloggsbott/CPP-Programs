//A Program to implement queues
#include<iostream>
using namespace std;

void insert(int q[],int max,int *back)
{
	if((*back)>=max-1)
		cout<<"Queue Overflow!!!";
	else
	{
		int data;		
		*back=*back+1;
		cout<<"\nEnter data to be inserted: ";
		cin>>data;
		q[*back]=data;
	}
}

void Delete(int q[],int *back)
{
	if(*back==-1)
		cout<<"\nQueue Empty";
	else
	{	int data=q[0];
		cout<<"\nDeleted data: "<<data;
		for(int i=0;i<=*back;i++)
			q[i]=q[i+1];
		*back=*back-1;
	}
}

void Display(int q[],int back)
{
	if(back==-1)
		cout<<"\nQueue Empty!!";
	else
	{	cout<<"\n";
		for(int i=0;i<=back;i++)
		{
			cout<<q[i];
			if(i!=back)
				cout<<"<-";
		}
	}
}

void frnt_n_back(int q[],int back)
{
	if(back==-1)
		cout<<"\nQueue Empty!!";
	else
		cout<<"\nFront element: "<<q[0]<<"\nBack Element: "<<q[back];
}

int main()
{
	int max,choice,back=-1;
	int *q;
	cout<<"\nEnter size of queue: ";
	cin>>max;
	q=new int(max);
	do
	{
		cout<<"\n\nMenu\n1.Insert\n2.Delete\n3.Display\n4.Front and Back\n5.Exit\nEnter Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: insert(q,max,&back);
				break;
			case 2: Delete(q,&back);
				break;
			case 3:	Display(q,back);
				break;
			case 4:	frnt_n_back(q,back);
				break;
		}
	}while(choice!=5);
	
	cout<<"\n\n";
	return 0;
}
