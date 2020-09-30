#include<bits/stdc++.h>
using namespace std;

int N,M;
#define MAX 300
int maps[MAX][MAX];
int visited[MAX][MAX]={0,};
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int year=0;

vector<pair<int,int> > v; // position ice 
int cntarr[10000];//minus cnt
 
void init()
{
	for(int i=0;i<N;++i)
	{
		memset(visited[i],0,sizeof(int)*M);
	}
}


void dfs2(int y,int x)//version2.0
{
	visited[y][x]=1;
	for(int i=0;i<4;++i)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(!visited[ny][nx]&&maps[ny][nx]!=0)//check visit && check sea 
		{
			dfs2(ny,nx);
		}
	}
}
int getisland(void)
{
	int count=0;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			if(maps[i][j]!=0&&!visited[i][j])
			{
				dfs2(i,j);
				count++;
			}
		}
	}
	return count;
}


int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			cin>>maps[i][j];
			if(maps[i][j]!=0)
				v.push_back({i,j});
		}
	}

	int num=getisland();

	while(num<2)
	{
		int n;

		for(int i=0;i<v.size();++i)
		{
			n=0;
			if(maps[v[i].first][v[i].second]!=0)
			{
				for(int j=0;j<4;j++)
				{
					int ny=v[i].first+dy[j];
					int nx=v[i].second+dx[j];
					if(maps[ny][nx]==0)
					{
						n++;

					}
				}

				cntarr[i]=n;

			}
			else
			{
					cntarr[i]=0;
			}
			
		}
//		
//		cout<<endl;
//		for(int i=0;i<N;++i) //circumstance now 
//		{
//			for(int j=0;j<M;++j)
//			{
//				cout<<maps[i][j]<<" ";
//			}
//			cout<<endl;
//		} 
//		cout<<endl;
		
		for(int i=0;i<v.size();++i)
		{
			maps[v[i].first][v[i].second]-=cntarr[i];
			if(maps[v[i].first][v[i].second]<0)
				maps[v[i].first][v[i].second]=0;
		}
//		for(int i=0;i<N;++i)		//circumstance after 1year 
//		{
//			for(int j=0;j<M;++j)
//			{
//				cout<<maps[i][j]<<" ";
//			}
//			cout<<endl;
//		} 
//		

		init();
		year++;
		num=getisland();

		if(num==0)
		{
			cout<<0;
			return 0;
		}
	}
	cout<<year;
	return 0;

	
}
