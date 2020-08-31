#include<bits/stdc++.h>
using namespace std;

int visitDFS[1000];	
int visitBFS[1000];
vector<int> a[1001];


void dfs(int start){
	if(visitDFS[start]){
		return;
	}
	visitDFS[start]=true;
	cout<<start<<" ";
	for(int i=0;i<a[start].size();++i)
	{
		int x=a[start][i];
		dfs(x);
	}
	
}
void bfs(int start){
	queue<int> q;
	q.push(start);
	visitBFS[start]=true;
	
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		for(int i=0;i<a[x].size();++i){
			int y=a[x][i];
			if(!visitBFS[y]){
				q.push(y);
				visitBFS[y]=true;
			}
		}
	}
}
int main()
{
	int N;
	cin>>N;

	int M;
	cin>>M;

	int V;
	cin>>V;

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
	dfs(V);
	cout<<endl;
	bfs(V);
	return 0;
}
