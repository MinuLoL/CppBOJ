#include<bits/stdc++.h>
using namespace std;
int N,K;
queue<int> q;
int visited[100001];
bool isInMap(int n){
	return (n >= 0 && n <= 100000);
} 
void bfs(int n,int k)
{

	q.push(n);
	visited[n]=1;
	while(q.front()!=k)
	{
		int num=q.front();
		q.pop();

		if(isInMap(num-1)&&!visited[num-1])
		{
			q.push(num-1);
			visited[num-1]=visited[num]+1;
		}
		if(isInMap(num+1)&&!visited[num+1])
		{
			q.push(num+1);
			visited[num+1]=visited[num]+1;	
		}
		if(isInMap(2*num)&&!visited[2*num])
		{
			q.push(2*num);
			visited[2*num]=visited[num]+1;
		}
	}
}
int main()
{
	cin>>N>>K;
	bfs(N,K);

	cout<<visited[K]-1<<endl;
	return 0;
}
