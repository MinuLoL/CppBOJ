#include<bits/stdc++.h>
using namespace std;

vector<int> v1[501];
vector<int> v2[501];
int N,M;
int a,b;
bool visited1[501]={0,};
bool visited2[501]={0,};
int cnt1=0;
int cnt2=0;
int ans=0;

void init()
{
	cnt1=0;cnt2=0;
	memset(visited1,false,sizeof(visited1));
	memset(visited2,false,sizeof(visited2));
}

void DFS1(int node)
{
	if(visited1[node])return;
	
	visited1[node]=true;
	cnt1++;
	for(int i=0;i<v1[node].size();++i)
	{
		DFS1(v1[node][i]);
	}
}
void DFS2(int node)
{
	if(visited2[node])return;
	
	visited2[node]=true;
	cnt2++;
	for(int i=0;i<v2[node].size();++i)
	{
		DFS2(v2[node][i]);
	}
}

int main()
{
	cin>>N>>M;
	for(int i=0;i<M;++i)
	{
		cin>>a>>b;
		v1[a].push_back(b);
		v2[b].push_back(a);
	}
	for(int i=1;i<=N;++i)
	{
		init();
		DFS1(i);
		DFS2(i);
		cnt1--;
		cnt2--;

		if((cnt1+cnt2)==(N-1))
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
