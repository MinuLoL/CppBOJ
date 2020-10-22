#include<bits/stdc++.h>
using namespace std;

int N,M;
char maps[11][11];
int Ry,Rx;
int By,Bx;
int Oy,Ox;
int gravCnt=0;

int bfs(int ry,int rx,int by,int bx)
{
	queue<pair<pair<pair<int,int>,pair<int,int> >,int> > q;	//(Ry,Rx),(By,Bx)
	q.push(make_pair(make_pair(make_pair(ry,rx),make_pair((by,bx))),0);
	
	while(!q.empty())
	{
		
		
//		if(ry==Oy&&rx==Ox)
//		{
//			return gravCnt;
//		}
	}
}


int main()
{
	cin>>N>>M;
	for(int i=0;i<N;++i)
	{
		cin>>maps[i];
		for(int j=0;j<M;++j)
		{
			if(maps[i][j]=='R')
			{
				Ry=i;
				Rx=j;
			}
			else if(maps[i][j]=='B')
			{
				By=i;
				Bx=j;
			}
			else if(maps[i][j]=='O')
			{
				Oy=i;
				Ox=j;
			}
		}
	}
//	cout<<"Rpos:"<<Ry<<" "<<Rx<<endl;
//	cout<<"Bpos:"<<By<<" "<<Bx<<endl;
//	cout<<"Opos:"<<Oy<<" "<<Ox<<endl;
	
}












