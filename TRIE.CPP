//A Program to implement Trie Structures
#include <iostream.h>
#include <conio.h>
#include <string.h>
typedef struct trienode
{
  char word[10];
  struct trienode *next1;
  struct trienode *next2;
  struct trienode *next3;
  struct trienode *next4;
  struct trienode *next5;
}tnode;
class TRIE
{
  trienode *root;
  public :
  TRIE()
  {
    root = new trienode;
    strcpy(root->word,"-");
    root->next1=NULL;
    root->next2=NULL;
    root->next3=NULL;
    root->next4=NULL;
    root->next5=NULL;
  }
  void trie_insert(char word[])
  {
  char cur;
  tnode *temp;
  int pos = 0,done=0;
  temp = root;
  while (!done)
  {
    tnode *newnode;
    newnode = new tnode;
    strcpy(newnode->word,"-");
    newnode->next1=NULL;
    newnode->next2=NULL;
    newnode->next3=NULL;
    newnode->next4=NULL;
    newnode->next5=NULL;
    cur = word[pos];
    switch (cur)
    {
      case 'a':
      case 'A': if (temp->next1 == NULL)
		{
		    temp->next1 = newnode;
		}
		temp=temp->next1; break;
      case 'c':
      case 'C': if (temp->next2 == NULL)
		{
		    temp->next2 = newnode;
		}
		temp=temp->next2;break;
      case 'e':
      case 'E': if (temp->next3 == NULL)
		{
		    temp->next3 = newnode;
		}
		temp=temp->next3;break;
      case 'm':
      case 'M': if (temp->next4 == NULL)
		{
		    temp->next4 = newnode;
		}
		temp=temp->next4;break;
      case 't':
      case 'T': if (temp->next5 == NULL)
		{
		    temp->next5 = newnode;
		}
		temp=temp->next5;break;
      case '\0':  strcpy(temp->word,word);
		  done = 1;

      }
      pos++;
    }
  }

  void trie_display()
  {
     trie_display(root);
  }
  void trie_display(trienode *rt)
  {
	if (rt!=NULL)
	{
		if (strcmp(rt->word, "-")!=0)
		{
			cout << rt->word << endl;
		}
		trie_display(rt->next1);
		trie_display(rt->next2);
		trie_display(rt->next3);
		trie_display(rt->next4);
		trie_display(rt->next5);
	}
  }
  void trie_search(char word[])
  {
	char cur;
	int done=0, pos=0;
	tnode *temp;
	temp = root;
	while (!done)
	{
		cur = word[pos];
		switch (cur)
		{
			case 'a':
			case 'A': if (temp->next1 == NULL)
				  {
					cout << "\nWrong word";
					done = 1;
					break;
				  }
				  temp=temp->next1;
				  break;
			case 'c':
			case 'C': if (temp->next2 == NULL)
				  {
					cout << "\nWrong word";
					done = 1;
					break;
				  }
				  temp=temp->next2;
				  break;
			case 'e':
			case 'E': if (temp->next3 == NULL)
				  {
					cout << "\nWrong word";
					done = 1;
					break;
				  }
				  temp=temp->next3;
				  break;
			case 'm':
			case 'M': if (temp->next4 == NULL)
				  {
					cout << "\nWrong word";
					done = 1;
					break;
				  }
				  temp=temp->next4;
				  break;
			case 't':
			case 'T': if (temp->next5 == NULL)
				  {
					cout << "\nWrong word";
					done = 1;
					break;
				  }
				  temp=temp->next5;
				  break;
			case '\0':if (strcmp(temp->word, "-")!=0)
				  {
					cout << "Your word is present in dictionary";
					done = 1;
				  }
		}
		pos++;
	}
  }
};
void main()
{
  TRIE T;
  int op, mlen;
  char word[10];
  do
  {
    cout<<"\nEnter your option : 1. Insert, 2. Search, 3. Display, 4. Exit ";
    cin >> op;
    switch(op)
    {
      case 1:
      {
	cout <<"\nEnter the word (with A, C, E, M, T only) to insert ";
	cin >> word;
	T.trie_insert(word); break;
      }
      case 2:
      {
	cout << "\nEnter the word to search ";
	cin >> word;
	T.trie_search(word); break;
      }
      case 3: T.trie_display(); break;
    }
  } while(op <= 3);
}
