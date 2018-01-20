//A Program to implement circular doubly linked list
#include<iostream>
using namespace std;
class dll
{
 struct node
 {
  int data;
  node* pre;
  node* next;
 }*head;
 public:
 dll()
 {
  head=NULL;
 }
 void insbeg(int val)
 {
  node* pnew=new node;
  pnew->data=val;
  pnew->pre=pnew;
  pnew->next=pnew;
  if(head!=NULL)
  {
   head->pre->next=pnew;
   head->pre=pnew;
  }
  head=pnew;
 }
 void insend(int val)
 {
  if(head==NULL)
  {
   node* pnew=new node;
   pnew->data=val;
   pnew->pre=pnew;
   pnew->next=pnew;
   head=pnew;
  }
  else 
  {
   node* cur=head->pre;
   node* pnew=new node;
   pnew->data=val;
   pnew->pre=cur;
   pnew->next=head;
   head->pre=pnew;
   cur->next=pnew;
  }
 }
 void insloc(int val,int loc)
 {
  node* cur=head;
  for(int i=1;i<loc && cur!=NULL;i++)
   cur=cur->next;
  if(cur==head)
   cout<<"INVALID LOCATION";
  else
  {
   node* pnew=new node;
   pnew->data=val;
   pnew->pre=cur;
   pnew->next=cur->next;
   cur->next->pre=pnew;
   cur->next=pnew; 
  }
 }
 void del(int val)
 {
  if(head->next==head && head->data==val)
   head=NULL;
  else
  {
   node* cur=head;
   while(cur!=NULL)
   {
    if(cur->data==val)
    {
     if(cur==head)
     {
      head=cur->next;
      head->pre=cur->pre;
      cur->pre->next=cur->pre;
     }
     else
     {
      cur->pre->next=cur->next;
      cur->next->pre=cur->pre;
     }
     node* t=cur;
     delete t;
    }
    cur=cur->next;
    if(cur==head)
     break;
   }
   if(cur==NULL)
    cout<<"DATA NOT FOUND ";
  }
 }
 int retrieve(int loc)
 {
  node* cur=head;
  for(int i=1;cur!=NULL;i++)
  {
   if(i==loc)
    return cur->data;
   cur=cur->next;
   if(cur==head)
    break;
  }   
  cout<<"INAVLID LOCATION";
  return -1;
 }
 int count()
 {
  node* cur=head;
  int i;
  for(i=0;cur!=NULL;i++)
  {
   cur=cur->next;
   if(cur==head)
    break;
  }
  return i;
 }
 void disp()
 {
  node* cur=head;
  while(cur!=NULL)
  {
   cout<<cur->data<<' ';
   cur=cur->next;
   if(cur==head)
    break;
  }
 }
};
int main()
{
 dll a;
 char ch;
 do{
  cout<<"1.INSERT AT BEG\n2.INSERT AT END\n3.INSERT AT MIDDLE\n4.DELETE\n5.RETRIEVE\n6.COUNT\n7.DISPLAY\nENTER CHOICE : ";
  int c,l,x;
  cin>>c;
  switch(c)
  {
   case 1:{
           cout<<"ENTER VALUE TO INSERT : ";
           cin>>x;
           a.insbeg(x);
           break;
          }
   case 2:{
           cout<<"ENTER VALUE TO INSERT : ";
           cin>>x;
           a.insend(x);
           break;
          }
   case 3:{
           cout<<"ENTER VALUE TO INSERT : ";
           cin>>x;
           cout<<"ENTER LOCATION : ";
           cin>>l;
           a.insloc(x,l);
           break;
          }
   case 4:{
           cout<<"ENTER VALUE TO DELETE : ";
           cin>>x;
           a.del(x);
           break;
          }
   case 5:{
           cout<<"ENTER LOCATION : ";
           cin>>l;
           cout<<a.retrieve(l);
           break;
          }
   case 6:{
           cout<<a.count();
           break;
          }
   case 7:{
           a.disp();
           break;
          }
   default :{
             cout<<"INCORRECT CHOICE";
            }
  }
  cout<<"DO YOU WANT TO CONTINUE ? ";
  cin>>ch;
 }while(ch=='y' || ch=='Y');
}
  
  
