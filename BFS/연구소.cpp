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
int min=0;

void init(void)
{
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			revmap[i][j]=maps[i][j]l
		}
	}
} 

void comb(int number,int idx)
{
	if(idx>=3)
	{
		for(int i=0;i<3;++i)
		{
			cout<<"("<<choice[i].first<<" "<<choice[i].second<<")"<<" ";
			pos[c][i][0]=choice[i].first;
			pos[c][i][1]=choice[i].second;
		}
		c++;
		cout<<endl;
		
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
			revmap[i][j]=mpas[i][j];
			if(maps[i][j]==0)
			{
				v.push_back(make_pair(i,j));
				cnt++;
			}
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
			for(int k=0;k<2;++k)
			{
				revmap[pos[i][j][k]][pos[i][j][k]]=1;
			}
		}
		//바이러스 위치인 2에서 BFS
		
		 
		
		
	}
	
	
	
	return 0;
}
