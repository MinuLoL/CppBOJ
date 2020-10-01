#include<bits/stdc++.h>
using namespace std;
#define MAX	100001

int N;
vector<int>v[MAX];
bool visited[MAX];

int parent[MAX];


void DFS(int x)
{
	visited[x]=true;
	for(int i=0;i<v[x].size();++i)
	{
		int next=v[x][i];
		if(!visited[next])
		{
			parent[next]=x;
			DFS(next);
		}
	}
}

int main()
{
	cin>>N;
	int x,y;
	for(int i=1;i<N;++i)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	DFS(1);
	for(int i = 2; i <= N; i++)
    	cout << parent[i] << '\n';
    
    return 0;
}

