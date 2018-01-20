//A Program to implement hash search 
#include<iostream>
using namespace std;
class hash
{
 int m;
 struct node
 {
  int data;
  node* link;
 }*head[10];
 public :
 hash()
 {
  m=10;
  for(int i=0;i<m;i++)
   head[i]=NULL;
 }
 void insert(int key)
 {
  int h=key%m;
  node* pnew=new node;
  pnew->data=key;
  pnew->link=head[h];
  head[h]=pnew;
 }
 int search(int key)
 {
  int h=key%m;
  if(head[h]==NULL)
  {
   cout<<"NO ELEMENT PRESENT ";
   return -1;
  }
  else
  {
   node* temp=head[h];
   for(int i=0;i<m && temp!=NULL;i++)
   {
    if(temp->data==key)
     return i+1;
    temp=temp->link;
   }
   cout<<"NOT FOUND ";
   return -1;
  }
 }
 void display()
 {
  for(int i=0;i<m;i++)
  {
   node* temp=head[i];
   while(temp!=NULL)
   {
    cout<<temp->data<<' ';
    temp=temp->link;
   }
   cout<<'\n';
  }
 }
};
int main()
{
 char ch;
 hash t;
 do{
  int k,c;
  cout<<"1.INSERT\n2.SEARCH\n3.DISPLAY\nENTER CHOICE : ";
  cin>>c;
  switch(c)
  {
   case 1 :
   {
    cout<<"ENTER VALUE : ";
    cin>>k;
    t.insert(k);
    break;
   }
   case 2 :
   {
    cout<<"ENTER VALUE : ";
    cin>>k;
    int x=t.search(k);
    if(x!=-1)
     cout<<"LOCATION : "<<x;
    break;
   }
   case 3 :
   {
    t.display();
    break;
   }      
   default :
   {
    cout<<"INCORRECT CHOICE ";
   }
  }
  cout<<"DO YOU WANT TO CONTINUE ?? ";
  cin>>ch;
 }while(ch=='y' || ch=='Y');
}   
   
