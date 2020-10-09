#include<bits/stdc++.h>
using namespace std;
#define MAX	101

int N;
int wantarr[MAX];
bool visited[MAX];
bool pass[MAX];
int cnt;
vector<int>v;	//몇번인지 기록

void DFS(int num)	
{
	visited[num]=true;
	
	int next=wantarr[num];
	
	if(!visited[next])
		DFS(next);	
	
	else if(!pass[next])
	{
		for(int i=next;i!=num;i=wantarr[i])	
		{
			cnt++;
			v.push_back(i);
		}
		cnt++;				
		v.push_back(num);
	}
	pass[num]=true;
}

int main()
{
	cin>>N;
	for(int i=1;i<=N;++i)
	{
		cin>>wantarr[i];
	}
	for(int i=1;i<=N;++i)
	{
		if(!visited[i])
			DFS(i);
	}
	cout<<cnt<<endl;
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}
