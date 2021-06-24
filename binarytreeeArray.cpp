#include<bits/stdc++.h>
using namespace std;

char tree[10];
void root(char key)
{
	if(tree[0] != '\0')
	{
		cout<<"Tree already has a root"<<endl;
	}
	else
	{
		tree[0] = key;
	}
}

void setLeft(char key,int parent)
{
	if(tree[parent] == '\0')
	{
		cout<<"cant set data at "<<parent<<endl;
	}
	else
	{
		tree[(2*parent)+ 1] = key;
	}
}

void setRight(char key,int parent)
{
	if(tree[parent] == '\0')
	{
		cout<<"cant set data at "<<parent<<endl;
	}
	else
	{
		tree[(2*parent) + 2] = key;
	}
}
void printTree()
{
	for(int i=0;i<10;++i)
	{
		cout<<tree[i]<<" "; 
	}
	cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	
	root('A');
	setLeft('B',0);
	setRight('C',0);	

	printTree();
	
	return 0;
}