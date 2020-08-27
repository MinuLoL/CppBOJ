#include<bits/stdc++.h>
using namespace std;
int N,M;
int visit[1000];
vector<int>a[1001];
int cnt=0;
void dfs(int start)
{
	if(visit[start])
	{
		return;
	}
	visit[start]=true;
//	cout<<start<<" ";
	for(int i=0;i<a[start].size();++i)
	{
		int x=a[start][i];
		dfs(x);
	}
}

int GetZeroVisit()
{
	for(int i=1;i<=N;++i)
	{
		if(visit[i]==false)
		{
			return i;
		}
	}
	return 0;
}
int main()
{
	cin>>N>>M;
	
	for(int i=0;i<M;++i)
	{
		int x;
		int y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=0;i<N+1;++i)
	{
		sort(a[i].begin(),a[i].end());
	}
	while(GetZeroVisit())
	{
		dfs(GetZeroVisit());
		cnt++;
	}
	cout<<cnt;
} 
