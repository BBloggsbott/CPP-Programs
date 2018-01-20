//A Program to implement Binary Search iteratively
#include<iostream>
using namespace std;

void binsrch(int a[], int size, int data)
{
	int low,mid,high;
	low=0;
	high=size-1;
	int flag=0;
	while((low<high)&&(!flag))
	{
		mid=(low+high)/2;
		if(a[mid]==data)
		{	cout<<"\nThe number "<<data<<" is present at position: "<<mid+1;	flag=1;	}
		else if(data<a[mid])
			high=mid-1;
		else
			low=mid+1;

	}
	
	if(!flag)
		cout<<"\nThe number "<<data<<"is not present in the input";
}

int main()
{
	int size,data,i;
	cout<<"\nEnter the number of elements: ";
	cin>>size;
	int a[size];
	cout<<"\nEnter the elements:";
	for(i=0;i<size;i++)
		cin>>a[i];

	cout<<"\nEnter the element to be searched for: ";
	cin>>data;
	
	binsrch(a,size,data);
	cout<<"\n\n";
	return 0;
}

