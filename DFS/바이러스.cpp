#include<bits/stdc++.h>
using namespace std;

int visitDFS[101];	
vector<int> a[101];


void dfs(int start){
	if(visitDFS[start]){
		return;
	}
	visitDFS[start]=true;
//	cout<<start<<" ";
	for(int i=0;i<a[start].size();++i)
	{
		int x=a[start][i];
		dfs(x);
	}
	
}

int main()
{
	int numOfCom;
	cin>>numOfCom;
	int Edge;
	cin>>Edge;
	int cnt=0;
	for(int i=0;i<Edge;++i)
	{
		int x;
		int y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);	
	}
	dfs(1);
	for(int i=2;i<=numOfCom;++i)
	{
		if(visitDFS[i]==true)
		{
			cnt++;
		}
	}
	cout<<cnt;
}
