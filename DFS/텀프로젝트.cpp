#include<bits/stdc++.h>
using namespace std;

#define MAX	100001

int n;
int arr[MAX];
bool visited[MAX];
bool pass[MAX];
int cnt;
vector<int>v;

void DFS(int num)
{
	visited[num]=true;
	
	int next=arr[num];
	if(!visited[next])
		DFS(next);
	else if(!pass[next])
	{
		for(int i=next;i!=num;i=arr[i])
			cnt++;
		cnt++;
	}
	pass[num]=true;
}

void init()
{
	cnt=0;
	memset(visited,false,sizeof(visited));
	memset(pass,false,sizeof(pass));
}

int main()
{
	int Testcase;
	cin>>Testcase;
	while(Testcase--)
	{
		init();
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>arr[i];
		}
		for(int i=1;i<=n;++i)
		{
			if(!visited[i])
				DFS(i);
		}
		v.push_back(n-cnt);
	}
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}
