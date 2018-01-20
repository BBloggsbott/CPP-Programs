//A Program to determine the minimum weighted spanning tree
#include <iostream.h>
#include <conio.h>
struct pqnode
{
   int index;
   int d;
};
class pqueue
{
   pqnode ver[10];
   int hsize;
   public:
      pqueue();
      int empty();
      void enqueue(int v, int key);
      int dequeue();
      void adjust(int i);
      void decrease_key(int v, int key);
};
pqueue::pqueue()
{
   hsize=0;
}
int pqueue::empty()
{
   if (hsize==0)
      return 1;
   else
      return 0;
}
void pqueue::enqueue(int v, int key)
{
  hsize++;
  int i=hsize;
  while (i/2>0 && (ver[i/2].d > key))
  {
     ver[i]=ver[i/2];
     i=i/2;
  }
  ver[i].index = v;
  ver[i].d = key;
}
int pqueue::dequeue()
{
  int x = ver[1].index;
  ver[1]=ver[hsize];
  hsize--;
  adjust(1);
  return x;
}
void pqueue::adjust(int i)
{
  int l=2*i;
  int r = 2*i +1;
  int smallest;
  if (l <=hsize && ver[l].d < ver[i].d)
    smallest = l;
  else
    smallest = i;
  if (r <= hsize && ver[r].d < ver[smallest].d)
    smallest = r;
  if (i != smallest)
  {
    pqnode t = ver[smallest];
    ver[smallest] = ver[i];
    ver[i] = t;
    adjust(smallest);
  }
}
void pqueue::decrease_key(int v, int key)
{
  for (int i=1; i<=hsize; i++)
     if (ver[i].index == v)
	 break;
  while (i/2>0 && (ver[i/2].d > key))
  {
     ver[i]=ver[i/2];
     i=i/2;
  }
  ver[i].index = v;
  ver[i].d = key;
}
struct adjnode
{
  int adjver;
  int w;
  adjnode *link;
};
struct gnode
{
   char name;
   int visited;
   int d;
   int pi;
   adjnode *edjptr;
};
class graph
{
  int n;
  gnode a[10];
  pqueue pq;
  public:
    graph();
    void getdata();
    void compute(int s);
    void display();
};
graph::graph()
{
  int i;
  for (i=0; i<10; i++)
  {
    a[i].visited=0;
    a[i].pi=-1;
    a[i].d = 999;
    a[i].edjptr=NULL;
  }
}
void graph::getdata()
{
   int m;
   cout << "Enter the number of vertices :";
   cin >> n;
   for (int i=0; i<n; i++)
   {
      cout << "Enter name of the vertex ";
      cin >> a[i].name;
      pq.enqueue(i, a[i].d);
      cout << "Enter the number of adjacent vertices for " << a[i].name <<" ";
      cin >> m;
      for (int j=0; j<m; j++)
      {
	cout << "Enter the index of the adjacent vertex-"<<j<<" ";
	adjnode *t = new adjnode();
	cin >> t->adjver;
	cout << "Enter the weight of the edge ("<<i<<", "<<t->adjver<<") ";
	cin >> t->w;
	t->link = a[i].edjptr;
	a[i].edjptr=t;
      }
   }
}
void graph::display()
{
   int tw=0;
   for (int i=0; i<n; i++)
   {
      if (a[i].pi != -1)
      {
	 int parent = a[i].pi;
	 tw += a[i].d;
	 cout << "(" <<a[parent].name <<", "<<a[i].name <<")"<<endl;
      }
   }
   cout << "Weight of the MWST is " << tw<<endl;
}
void graph::compute(int s)
{
   a[s].visited=1;
   a[s].pi=-1;
   a[s].d = 0;
   pq.decrease_key(s, a[s].d);
   while (!pq.empty())
   {
      int u = pq.dequeue();
      a[u].visited=1;
      adjnode *temp = a[u].edjptr;
      while (temp!= NULL)
      {
	int v=temp->adjver;
	if (a[v].visited==0 && a[v].d > temp->w)
	{
	   a[v].pi = u;
	   a[v].d = temp->w;
	   pq.decrease_key(v, a[v].d);
	}
	temp=temp->link;
      }
   }
}
void main()
{
  graph g;
  int s;
  g.getdata();
  cout << "Enter the index of source vertex ";
  cin >> s;
  g.compute(s);
  cout << "The edges included in the MWST are: " << endl;
  g.display();
}
