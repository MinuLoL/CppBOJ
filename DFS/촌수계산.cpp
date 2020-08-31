#include<bits/stdc++.h>
using namespace std;

int visitDFS[100];	
vector<int> a[101];

void dfs(int start,int end,int count){
	if(visitDFS[start]){
		return;
	}
	visitDFS[start]=true;
	if(start==end)
		cout<<count;
	for(int i=0;i<a[start].size();++i)
	{
		int x=a[start][i];
		dfs(x,end,count+1);
	}


}
int main()
{
	int n;
	cin>>n;

	int v1,v2;
	cin>>v1>>v2;

	int m;
	cin>>m;

	for(int i=0;i<m;++i)
	{
		int x;
		int y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);		
	}
	dfs(v1,v2,0); //7 3
	if(!visitDFS[v2])
		cout<<-1;
	return 0;
}
