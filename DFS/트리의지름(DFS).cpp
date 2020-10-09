#include<bits/stdc++.h>
using namespace std;

#define MAX	100001

int V;	//number of vertex 
bool visited[MAX];	//check visited
vector<pair<int,int> > v[MAX];	//save node's vertex

int diameter=0;	
int farthestNode=0;

void init()
{
	diameter=0;
	memset(visited,false,sizeof(visited));
}

void DFS(int node,int cost)
{
	if(visited[node])
		return;
		
	visited[node]=true;
	
	if(diameter<cost)
	{
		diameter=cost;
		farthestNode=node;
	}
	for(int i=0;i<v[node].size();++i)
		DFS(v[node][i].first,cost+v[node][i].second);
}


int main()
{
	cin>>V;
	
	for(int i=0;i<V;++i)
	{
		int node;
		cin>>node;
		
		while(1)
		{
			int node2,cost;
			cin>>node2;
			if(node2==-1)
				break;
			cin>>cost;
			v[node].push_back({node2,cost});
		}
	}
	
	DFS(1,0);	//get farthestNode from random node->this's diameter is not max diameter
	init();
	DFS(farthestNode,0);	//get max diameter from route node(farthestNode)
	
	cout<<diameter;
	return 0;
}
