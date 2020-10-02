#include<bits/stdc++.h>
using namespace std;
#define MAX	100001

int Testcase,n;
int arr[MAX];
bool visited[MAX]; 
bool visited2[MAX];  
int cntvisited[MAX];
int firstnum;
int nextn;
int cnt;
int sum=0;

vector<int> sumv;

void init()
{
	cnt=0;
}

int DFS(int x)
{
	if(visited2[x])
	{
		return cnt-cntvisited[x]+1;
	}
	if(visited[x])
	{
		return 0;
	}
	
	visited[x]=true;
	visited2[x]=true;
	cnt++;
	cntvisited[x]=cnt;
	nextn=arr[x];
	
	if(nextn==firstnum)
	{
		return cnt;
	}
	else if(nextn==x)
	{
		return 1;
	}
	else if(nextn!=firstnum)
	{
		return DFS(nextn);
	}
	
	
}


int main()
{
	cin>>Testcase;
	while(Testcase--)
	{
		sum=0;
		
		cin>>n;
		
		for(int i=1;i<=n;++i)
		{
			cin>>arr[i];
		}
		for(int i=1;i<=n;++i)
		{
			if(visited[i])
			{
				continue;
			}
			firstnum=i;
			init();
			sum+=DFS(i);
			memset(visited2,0,sizeof(visited2));
		}
		
		sumv.push_back(n-sum);
		memset(arr,0,sizeof(arr));
		memset(visited,0,sizeof(visited));
	}
	
	for(int i=0;i<sumv.size();++i)
	{
		cout<<sumv[i]<<'\n';
	}
	return 0;
}

