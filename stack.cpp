//A Program to implement stack operations
#include<iostream>
using namespace std;

void push(int stack[],int max,int *top)
{
	if(*top>=max)
		cout<<"\nSTACK OVERFLOW!!!";
	else
	{
		*top=*top+1;
		int data;		
		cout<<"\nEnter the number to be pushed: ";
		cin>>data;
		stack[*top]=data;
	}
}

void pop(int stack[],int *top)
{
	if(*top==-1)
		cout<<"\nSTACK EMPTY!!";
	else
	{
		cout<<"\nThe popped element is "<<stack[*top];
		*top=*top-1;
	}
}

void peek(int stack[], int top)
{
	if(top==-1)
		cout<<"\nSTACK EMPTY";
	else
	{
		cout<<"\nTop element: ";
		cout<<stack[top];
	}
}

void display(int stack[],int top)
{
	if(top==-1)
		cout<<"\nSTACK EMPTY!!";
	else 
	{
		int i=top;
		cout<<"\n";
		while(i>=0)
		{
			cout<<stack[i];
			if(i!=0)
				cout<<"->";
			i=i-1;
		}
	}
}


int main()
{
	int choice=0,max,top=-1;
	cout<<"\nEnter size of stack: ";
	cin>>max;
	int *stack;
	stack=new int(max);
	while(choice!=5)
	{
		cout<<"\n\nMenu:\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:	push(stack,max,&top);
				break;
			case 2:	pop(stack,&top);
				break;
			case 3:	peek(stack,top);
				break;
			case 4: display(stack,top);
				break;
		}
	}
	
	cout<<"\n\n";
	delete stack;
	return 0;
}
