#include<bits/stdc++.h>
using namespace std;

int N,M;
int maps[8][8];
vector<pair<int,int> > v;

vector<pair<int,int> > choice(8);
int cnt;

void comb(int number,int idx)
{
	if(idx>=3)
	{
		for(int i=0;i<3;++i)
			cout<<"("<<choice[i].first<<" "<<choice[i].second<<")"<<" ";
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
			if(maps[i][j]==0)
			{
				v.push_back(make_pair(i,j));
				cnt++;
			}
		}
	}
	comb(0,0);
	return 0;
}
