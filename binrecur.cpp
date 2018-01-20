//A Program to implement binary search using a recursive function
#include<iostream>
using namespace std;
int binsrch(int data, int a[], int low, int high)
{
	int mid=(low+high)/2;
	if(a[mid]==data)
	{
		cout<<"\nThe element "<<data<<" is present at position: "<<mid+1;
		return 1;
	}
	else
	{
		if(low<high)
		{
			if(data<a[mid])
				high=mid-1;
			else
				low=mid+1;
		}
		else
			return 0;
		
		return binsrch(data,a,low,high);
	}

}

int main()
{
	int size,data,low,high;
	cout<<"\nEnter the size: ";
	cin>>size;
	int a[size],flag=0;
	cout<<"\nEnter the elements: ";
	for(int i=0;i<size;i++)
		cin>>a[i];
	
	cout<<"\nEnter the element to be searched for: ";
	cin>>data;

	low=0;
	high=size-1;
	
	flag=binsrch(data,a,low,high);

	if(!flag)
		cout<<"\nThe element is not present in the input!!";

	cout<<"\n\n";
	return 0;
}
