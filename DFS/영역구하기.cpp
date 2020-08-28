#include<bits/stdc++.h>
using namespace std;
int M,N,K,cnt=0;
int maps[100][100];
bool visited[100][100];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int empcnt;
vector<int> v;

void init() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

bool isInMap(int y, int x){
	return ((y >= 0 && y < M) && (x >= 0 && x < N));
} 
 void dfs(int y, int x) {
	visited[y][x] =true;
	empcnt++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(isInMap(ny,nx)&&!visited[ny][nx]&&maps[ny][nx])
			dfs(ny, nx);
		}
}
int main()
{
	int x1,y1,x2,y2;
	cin>>M>>N>>K;
	memset(maps,1,sizeof(maps));
	for(int i=0;i<K;++i)
	{
		cin>>x1>>y1>>x2>>y2;
		for(int j=M-y2;j<M-y1;++j)
		{
			for(int k=x1;k<x2;++k)
			{
				maps[j][k]=0;
			}
		}
	}
	init();
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (maps[i][j] && !visited[i][j]) {
				dfs(i, j);
				v.push_back(empcnt);
				empcnt=0;
				cnt++;
			}
		}
	}
	sort(v.begin(),v.end());
	cout << cnt << endl;
	
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<" ";
	}
	return 0;

}
