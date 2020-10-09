#include<bits/stdc++.h>
using namespace std;
#define MAX	10001

int N,M;
vector<int>v[MAX];
bool visited[MAX];
int cnt=0;
int arr[MAX]={0,};
void init()
{
	memset(visited,false,sizeof(visited));
	cnt=0;
}

void DFS(int node)
{
	if(visited[node])
		return;
	visited[node]=true;
	cnt++;
	for(int i=0;i<v[node].size();++i)
	{
		DFS(v[node][i]);
	}
}

int main()
{
	cin>>N>>M;
	
	for(int i=0;i<M;++i)
	{
		int x,y;
		cin>>x>>y;
		v[y].push_back(x);
	}
	int max=0;
	for(int i=1;i<=N;++i)
	{
		DFS(i);
		arr[i]=cnt;
		if(max<cnt)
			max=cnt;
		init();
	}
	for(int i=1;i<=N;++i)
	{
		if(arr[i]==max)
			cout<<i<<endl;
	}
	return 0;
}
