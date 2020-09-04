#include<bits/stdc++.h>
using namespace std;

#define MAX 50
int maps[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int T, M, N, K, X, Y, cnt;
vector<int> ans;

bool isInMap(int y, int x){
	return ((y >= 0 && y < N) && (x >= 0 && x < M));
} 

void bfs(int y,int x)
{
	queue < pair<int,int> > q;
	q.push(make_pair(y,x));
	visited[y][x]=1;
	
	while(!q.empty()){
		y=q.front().first;
		x=q.front().second;
		q.pop();
		for(int i=0;i<4;++i)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(isInMap(ny,nx)&&!visited[ny][nx]&&maps[ny][nx])
			{
				visited[ny][nx]=1;
				q.push(make_pair(ny,nx));
			}
		}
	}
}
void init() {
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			maps[i][j] = 0;
			visited[i][j] = false;
		}
	}

}

int main() {
	cin >> T;

	while (T--) {
		init();
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			if (X < 0 || X >= M || Y < 0 || Y >= N)
				continue;
			maps[Y][X] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (maps[i][j] && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		ans.push_back(cnt);
	}
	for(int i=0;i<ans.size();++i)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}

