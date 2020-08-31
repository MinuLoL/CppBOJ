#include<bits/stdc++.h>
using namespace std;
char maps[100][100];
int visited[100][100];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};	
int N;
int cnt=0;	
bool isInMap(int y, int x){
	return ((y >= 0 && y < N) && (x >= 0 && x < N));
} 

void dfs(int y, int x) {
	visited[y][x] = true;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(isInMap(ny,nx)&&!visited[ny][nx]&&maps[ny][nx]==maps[y][x])
			dfs(ny, nx);
	}
}

void init() {
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(maps[i][j]=='R'||maps[i][j]=='G')
			{
				maps[i][j]='S';
			}
			visited[i][j] = false;
		}
	}

}
int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;j++)
		{
			cin>>maps[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (maps[i][j] && !visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout<<cnt<<" ";
	init();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (maps[i][j] && !visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout<<cnt;
}
