//A Program to implement Heap Sort
#include<iostream>
using namespace std;
void adjust(int a[],int i,int s)
{
	int l=2*i+1,r=2*i+2,lar;
	if(l<=s&&a[l]>a[i])
		lar=l;
	else
		lar=i;
	if(r<=s&&a[lar]<a[r])
		lar=r;
	if(lar!=i)
	{
		int temp=a[lar];
		a[lar]=a[i];
		a[i]=temp;
		adjust(a,lar,s);
	}
}
void heap(int a[],int n)
{
	int i=n/2;
	while(i>=0)
	adjust(a,i--,n);
}
void sort(int a[],int n)
{
	heap(a,n);
	int q=n;
	while(q>=1)
	{
		int temp=a[0];
		a[0]=a[q];
		a[q]=temp;
		n--;q--;
		adjust(a,0,n);
	}
}
int main()
{
	int a[20],n;
	cout<<"\nEnter no. of elements: ";
	cin>>n;
	cout<<"\nEnter the elements: ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,n-1);

	cout<<"\nThe sorted elements are: ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n\n";	
	return 0;
}

