#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Edge
{
public:
	int source;
	int destination;
	int weight;
};

bool func(Edge e1,Edge e2)
{
	return e1.weight < e2.weight;
}

int findParent(int x,int *parent)
{
	if(parent[x] == x)
		return x;

	return findParent(parent[x],parent);
}

void kruskal(Edge *input,int V,int E)
{
	Edge *output = new Edge[V-1];

	sort(input,input,func);
	int i=0;int count = 0;
	int *parent = new int[V];
	
	for(int i=0;i<V;++i)
	{
		parent[i] = i;
	}

	while(count != V-1)
	{
		Edge currentEdge = input[i];
		int sourceParent = findParent(currentEdge.source,parent);
		int destinationParent = findParent(currentEdge.destination,parent);
		if(sourceParent != destinationParent)
		{
			output[count] = currentEdge;
			count++;
			parent[sourceParent] = destinationParent;
		}
		i++;
	}
	for(int i=0;i<V-1;++i)
	{
		if(output[i].source < output[i].destination)
		{
			cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
		}
		else
		{
			cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	int V,E;
	int s,d,w;
	cin>>V>>E;
	Edge *input = new Edge[E];
	for(int i=0;i<E;++i)
	{
		cin>>s>>d>>w;
		input[i].source = s;
		input[i].destination = d;
		input[i].weight = w;
	}
	kruskal(input,V,E);
	return 0;
}