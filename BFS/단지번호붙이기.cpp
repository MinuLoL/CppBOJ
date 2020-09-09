#include<bits/stdc++.h>
using namespace std;

int N,M;
int maps[8][8];
int revmap[8][8];
int pos[1000000][3][2];
vector<pair<int,int> > v;
int c=0;
vector<pair<int,int> > choice(8);
int cnt;
int minnum=64;
int visited[8][8];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int realcnt;
int twocnt=0;
bool isInMap(int y,int x)
{
	return ((y >= 0 && y < N) && (x >= 0 && x < M));
}
bool check(int n)
{
	if(n==0)
		return true;
	else
		return false;
}
void bfs(int y,int x)
{
	queue<pair<int,int> > q;
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
			if(isInMap(ny,nx)&&!visited[ny][nx]&&check(revmap[ny][nx]))
			{
				visited[ny][nx]=1;
				realcnt++;
				q.push(make_pair(ny,nx));
			}
		}
	}
}
void init(void)
{
	realcnt=0;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			revmap[i][j]=maps[i][j];
			visited[i][j]=0;
		}
	}

} 

void comb(int number,int idx)
{
	if(idx>=3)
	{
		for(int i=0;i<3;++i)
		{
//			cout<<"("<<choice[i].first<<" "<<choice[i].second<<")"<<" ";
			pos[c][i][0]=choice[i].first;
			pos[c][i][1]=choice[i].second;
		}
		c++;
//		cout<<endl;
		
		return;
	}
	if(number>=cnt)
		return;
		
		choice[idx]=v[number];
		comb(number+1,idx+1);
		comb(number+1,idx);
}





int main()
{
	cin>>N>>M;
	
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			cin>>maps[i][j];
			revmap[i][j]=maps[i][j];
			if(maps[i][j]==0)
			{
				v.push_back(make_pair(i,j));
				cnt++;
			}
			if(maps[i][j]==2)
				twocnt++;
		}
	}
	comb(0,0);
//	for(int i=0;i<c;++i) //c는 부분집합의 갯수. 즉, 3개의 점을 배치할 수 있는 경우의 수 
//	{
//		for(int j=0;j<3;++j)
//		{
//			for(int k=0;k<2;++k)
//			{
//				cout<<pos[i][j][k]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
	for(int i=0;i<c;++i)
	{
		init();
		for(int j=0;j<3;++j)
		{
			
			revmap[pos[i][j][0]][pos[i][j][1]]=1;
			
		}
		//바이러스 위치인 2에서 BFS
		
//		for(int i=0;i<N;++i)
//		{
//			for(int j=0;j<M;++j)
//			{
//				cout<<revmap[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<M;++j)
			{
				if(!visited[i][j]&&revmap[i][j]==2)
				{
					realcnt++;
					bfs(i,j);
				}
			}
		}
//		cout<<"!:"<<realcnt<<endl;
		if(minnum>realcnt)
		{
			minnum=realcnt;
		}
		
	}
	cout<<cnt+twocnt-3-minnum;  //0의 개수+2의 개수-1넣을 개수(3)-2(바이러스)퍼진갯수최소
	
	return 0;
}
