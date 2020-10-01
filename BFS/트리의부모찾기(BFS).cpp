#include<bits/stdc++.h>
using namespace std;
#define MAX	100001

int N;
vector<int>v[MAX];
bool visited[MAX];

int parent[MAX];


void BFS(int x)
{
	queue<int>q;
	q.push(x);
	visited[x]=true;
	
	while(!q.empty())
	{
		int a=q.front();
		q.pop();
		for(int i=0;i<v[a].size();++i)
		{
			int y=v[a][i];
			if(!visited[y])
			{
				q.push(y);
				parent[y]=a;
				visited[y]=true;
			}
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
	BFS(1);
	for(int i = 2; i <= N; i++)
    	cout << parent[i] << '\n';
    
    return 0;
}

