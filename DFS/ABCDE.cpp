#include<bits/stdc++.h>
using namespace std;

vector<int> v[2001];
bool visited[2001]={0,};
int N,M;
bool check;

void dfs(int node,int cnt)
{
	if(visited[node])
		return;
		
	visited[node]=true;
	if(cnt==5)
	{
		check=true;
		return;
	}
	for(int i=0;i<v[node].size();++i)
	{
		dfs(v[node][i],cnt+1);
	}
	visited[node]=false;	//highlight point 
}

int main()
{
	cin>>N>>M;
	for(int i=0;i<M;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for(int i=0;i<N;++i)
	{
		dfs(i,1);
		if(check)
		{
			cout<<1;
			return 0;
		}
	}

	cout<<0;
	return 0;
}
