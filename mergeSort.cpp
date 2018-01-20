//A Program to implement Merge Sort
#include<iostream>
using namespace std;
void merge(int k[],int low,int mid,int high);
void mergesort(int k[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=((low+high)/2);
		mergesort(k,low,mid);
		mergesort(k,mid+1,high);
		merge(k,low,mid,high);
	}
}
void merge(int k[],int low,int mid,int high)
{
	int temp[50],i=low,j=mid+1,h=low;
	//cout<<"low"<<i<<"high"<<j<<"mod:"<<mid;
	while(i<=mid&&j<=high)
	{

		if(k[i]<=k[j])
	 	{
		temp[h]=k[i];
		i++;
		}
		else
		{	
			temp[h]=k[j];
			j++;
		}
		h++;
	}
	while(j<=high)
	{
		temp[h]=k[j];
		j++;h++;
	}

	while(i<=mid)
	{
		temp[h]=k[i];
		i++;h++;
	}

	i=low;
	while(i<=high)
	{
		k[i]=temp[i];
		i++;
	}
	return;

}
int main()
{
	int c[50],n;
	cout<<"\nEnter the limit: ";
	cin>>n;
	cout<<"\nEnter the array: ";
	for(int i=0;i<n;i++)
		cin>>c[i];
	mergesort(c,0,n-1);
	cout<<"\nThe array is: ";
	for(int i=0;i<n;i++)
		cout<<c[i]<<" ";cout<<endl;
	return 0;
}
