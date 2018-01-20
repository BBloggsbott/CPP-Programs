//A Program to implement Breadth First Search
#include <iostream.h>
struct node
{
   int data;
   node *link;
};

struct gnode
{
  char name[10];
  int dist;
  int dfn;
  int visited;
  node *eptr;
};
class queue
{
   int q[10], f, r;
   public:
   queue() { f=-1; r=-1;}
   int empty()
   {
     if (f==-1) return 1;
     else return 0;
   }
   void enqueue(int x)
   {
     if (r==10)
     {
	cout << "Queue overflows" << endl;
	return;
     }
     q[++r] = x;
     if (f==-1) f++;
     return;
   }
   int dequeue()
   {
     int x;
     if (r==-1)
     {
       cout << "Queue Empty" << endl;
       return -1;
     }
     x=q[f];
     if (f==r)
	f=r=-1;
     else
       f--;
     return x;
   }
};

class graph
{
  gnode v[10];
  int n;
  int count;

  public:
     void construct()
     {
	int m, adj;
	node *p;
	cout << "Enter no. of vertices : ";
	cin >> n;
	for (int i=0; i<n; i++)
	{
	  cout << "Enter the name of the vertex ";
	  cin >> v[i].name;
	  v[i].eptr=NULL;
	  cout << "Enter no. of adjacent vertices for " << v[i].name << " ";
	  cin >> m;
	  for (int j=0; j<m; j++)
	  {
	    cout << "Enter the index of " << j << "th adjacent vertex for " << v[i].name << " ";
	    cin >> adj;
	    p=new node;
	    p->data=adj;
	    p->link=NULL;
	    if (v[i].eptr == NULL)
	       v[i].eptr=p;
	    else
	    {
	      p->link = v[i].eptr;
	      v[i].eptr = p;
	    }
	  }
	}
     }
     void initialize()
     {
	count = 0;
	for (int i=0; i<n; i++)
	{
	   v[i].dist=0;
	   v[i].dfn = 0;
	   v[i].visited=0;
	}
     }
     void BFS(int u)
     {
	queue Q;
	node *t;
	int w;
	initialize();
	v[u].dist=0;
	v[u].visited=1;
	Q.enqueue(u);
	while (!Q.empty())
	{
	  u=Q.dequeue();
	  t=v[u].eptr;
	  while (t!= NULL)
	  {
	    w=t->data;
	    if (v[w].visited == 0)
	    {
	      v[w].dist = v[u].dist+1;
	      v[w].visited = 1;
	      cout << v[u].name << " --> " << v[w].name << endl;
	      Q.enqueue(w);
	    }
	    t = t->link;
	  }
	}
     }
     void DFS(int u)
     {
       node *t;
       int w;
       count++;
       v[u].dfn=count;
       v[u].visited=1;
       t=v[u].eptr;
       while (t!=NULL)
       {
	  w=t->data;
	  if (v[w].visited == 0)
	  {
	     cout << v[u].name << " --> " << v[w].name << endl;
	     DFS(w);
	  }
	  t=t->link;
       }
     }
     void display()
     {
       cout <<"No.\tName\tAdjacent Node List " << endl;
       for (int i=0; i<n; i++)
       {
	  cout << i << "\t" << v[i].name << "\t";
	  node *t=v[i].eptr;
	  while (t!=NULL)
	  {
	    cout << "--> " << t->data;
	    t=t->link;
	  }
	  cout << endl;
       }
       cout << "Edges used in the traversal are : " << endl;
     }
};

void main()
{
  graph G;
  int v, op;
  G.construct();
  do
  {
    cout << "1- BFS  2- DFS 3- Exit \nEnter your option " << endl;
    cin >> op;
    switch (op)
    {
      case 1:
      {
	cout << "Enter the index of starting vertex " ;
	cin >> v;
	G.initialize();
	G.display();
	G.BFS(v);
	break;
      }
      case 2:
      {
	cout << "Enter the index of starting vertex ";
	cin >> v;
	G.initialize();
	G.display();
	G.DFS(v);
	break;
      }
    }
  }
  while (op < 3);
}
