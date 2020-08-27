#include<bits/stdc++.h>
using namespace std;

int w,h,cnt,X,Y;
int maps[50][50];
bool visit[50][50];
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};
vector<int> v;
bool isInMap(int y, int x){
	return ((y >= 0 && y < h) && (x >= 0 && x < w));
} 
void dfs(int y,int x)
{
	visit[y][x]=true;
	for(int i=0;i<8;++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(isInMap(ny,nx)&&!visit[ny][nx] &&maps[ny][nx])
			dfs(ny, nx);
	}

}
void init() {
	cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			maps[i][j] = 0;
			visit[i][j] = false;
		}
	}
}
int main()
{
	cin>>w>>h;
	while(w!=0&&h!=0)
	{
		init();
		for(int i=0;i<h;++i)
		{
			for(int j=0;j<w;++j)
			{
				cin>>maps[i][j];
			}
		}
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (maps[i][j] && !visit[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		v.push_back(cnt);
		cin>>w>>h;				
	}
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<endl;
	}
}
