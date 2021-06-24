#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
	int source,dest,weight;
};

bool compare(Edge e1,Edge e2)
{
	return e1.weight<e2.weight;
}

int findParent(int v,int *parent)
{
	if(parent[v] == v)
			return v;
	return findParent(parent[v],parent);
}

void kruskal(Edge *input,int n,int e)
{
	Edge *output = new Edge[n-1];
	//sort the edges based on their wieghts 
	sort(input,input+e,compare);
	// creating the parent array Initially each element is a parent of iteself
	int *parent = new int[n];
	for(int i=0;i<n;++i)
	{
		parent[i] = i;
	}

	int i=0;
	int count = 0;
	//since we have n vertices there for the mininmu spanning tree will contain the (n-1) edges
	while(count!=(n-1))
	{
		Edge currentEdge = input[i];
		// Findiing the parenet of source and destination
		int sourceParent = findParent(currentEdge.source,parent);
		int desParent = findParent(currentEdge.dest,parent);
		if(sourceParent!=desParent)
		{
			output[count] = currentEdge;
			count++;
			parent[sourceParent] = desParent;
		}
		i++;
	}
	for(int i=0;i<n-1;i++)
	{
		if(output[i].source<output[i].dest)
		{
			cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		}
		else
		{
			cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
		}
	}
}


int main()
{
	int n,E;
	cin>>n>>E;
	Edge *input = new Edge[E];
	int s,d,w;
	for(int i=0;i<E;++i)
	{
		cin>>s>>d>>w;
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	kruskal(input,n,E);
}