#include<iostream>
using namespace std;

#define MAX 50
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int T, M, N, K, X, Y, cnt;	//M: 가로, N: 세로

bool isInMap(int y, int x){
	return ((y >= 0 && y < N) && (x >= 0 && x < M));
} 

void dfs(int y, int x) {
	visited[y][x] = true;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(isInMap(ny,nx)&&!visited[ny][nx]&&map[ny][nx])
			dfs(ny, nx);
		}
}

void init() {
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = 0;
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
			map[Y][X] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}

