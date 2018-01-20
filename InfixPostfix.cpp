//A Program to convert Infix Expression to Portfix Expression
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int top=-1;
int priority(char ch)
{
 if(ch=='^')
  return 3;
 else if(ch=='*' || ch=='/')
  return 2;
 else if(ch=='+' || ch=='-')
  return 1;
 else
  return 0;
}
void push(char s[100],char t)
{
 if(top!=99)
  s[++top]=t;
}
void pop(char s[100],char& t)
{
 if(top!=-1)
  t=s[top--];
}
int emptystack()
{
 if(top==-1)
  return 1;
 return 0;
}
void stacktop(char s[100],char& t)
{
 t=s[top];
}
char* intopost(char e[20],char post[20])
{
 char s[100],t,to,tt;
 int j=0;
 for(int i=0;i<strlen(e);i++)
 {
  t=e[i];
  if(t=='(')
   push(s,t);
  else if(t==')')
  {
   pop(s,t);
   while(t!='(')
   {
    post[j++]=t;
    pop(s,t);
   }
  }
  else if(t=='+' || t=='-' || t=='*' || t=='/' || t=='^')
  {
   stacktop(s,tt);
   while(!emptystack() && priority(t)<=priority(tt))
   {
    pop(s,to);
    post[j++]=to;
    stacktop(s,tt);
   }
   push(s,t);
  }
  else
   post[j++]=t;
 }
 while(!emptystack())
 {
  pop(s,t);
  post[j++]=t;
 }
 top=-1;
 post[j]='\0';
}
int main()
{
 char e[20],p[20];
 cout<<"Enter the Infix Expression ";
 cin>>e;
 intopost(e,p);
 cout<<"Postfix Expression : ";
 cout<<p<<"\n\n";
}
