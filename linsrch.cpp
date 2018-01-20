//A Program to implement Linear Search
#include<iostream>
using namespace std;

void linsrch(int data, int a[], int size)
{
	int i,flag=0;
	for(i=0;i<size;i++)
	{
		if(a[i]==data)
		{
			cout<<"\nThe Number "<<data<<" is present in position: "<<i+1;
			flag=1;
		}
	}
	
	if(!flag)
		cout<<"\nThe number "<<data<<" is not present in the input!!!";

}

int main()
{
	int i,size, data;
	cout<<"\nEnter the size of the array: ";
	cin>>size;
	int a[size];
	cout<<"\n\nEnter the array: \n";
	for(i=0;i<size;i++)
		cin>>a[i];

	cout<<"\nEnter the number to be searched for: ";
	cin>>data;
	
	linsrch(data,a,size);
	cout<<"\n";	
	return 0;
}
