#include<bits/stdc++.h>
using namespace std;

int maps[5][5];
bool visited[1000000];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int cnt=0;
int sum=0;
bool isInMap(int y,int x)
{
	return ((y>=0&&y<5)&&(x>=0&&x<5));
}

void dfs(int y,int x)
{
	cnt++;
	if(cnt==5)
	{
		if(!visited[sum])
		{
			ans++;
			visited[sum]=true;
		}
		cnt=0;
		sum=0;
		return;
	}
	sum+=maps[y][x]*pow(10,6-cnt);
	for(int i=0;i<4;++i)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(isInMap(ny,nx))
		{
			dfs(ny,nx);
		}
	}
}


int main()
{
	for(int i=0;i<5;++i)
	{
		for(int j=0;j<5;++j)
		{
			cin>>maps[i][j];
		}
	}
	

}
