#include<bits/stdc++.h>
using namespace std;
int maps[100][100];
int mapcp[100][100];
bool visited[100][100];
int cnt=0;	
int N;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<int> v;
bool isInMap(int y, int x){
	return ((y >= 0 && y < N) && (x >= 0 && x < N));
} 


void dfs(int y, int x) {
	visited[y][x] = true;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(isInMap(ny,nx)&&!visited[ny][nx]&&mapcp[ny][nx])
			dfs(ny, nx);
		}
}

void init() {
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mapcp[i][j]=0;
			visited[i][j] = false;
		}
	}

}

int main()
{

	cin>>N;
	int max=0;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			cin>>maps[i][j];	
			if(max<maps[i][j])
			{
				max=maps[i][j];
			}
		}	
	}	
	while(max--)//높이가 최대에서 1일때까지 
	{
		init();
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
			{
				mapcp[i][j]=maps[i][j];	
				
			}	
		}
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
			{
				if(mapcp[i][j]<=max)
				{
					mapcp[i][j]=0;
				}
				else
				{
					mapcp[i][j]=1;
				}
			}
		}
		
		 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mapcp[i][j] && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		v.push_back(cnt);
//		cout<<cnt<<" ";
	}
	vector<int>::iterator iter;
	iter=max_element(v.begin(),v.end());
	cout<<*iter;
	return 0;
} 
