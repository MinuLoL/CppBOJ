#include<bits/stdc++.h>
using namespace std;

int visitBFS[1000];
vector<int> a[1001];
int cnt=0;
void bfs(int start){
	queue<int> q;
	q.push(start);
	visitBFS[start]=true;
	
	while(!q.empty()){
		int x=q.front();
		q.pop();
//		cout<<x<<" ";
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


	for(int i=0;i<M;++i)
	{
		int x;
		int y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);		
	}
	for(int i=1;i<=N;++i)
	{
		if(visitBFS[i]==0)
		{
			bfs(i);
			cnt++;
		}
	}
	cout<<cnt;
	return 0; 
}
