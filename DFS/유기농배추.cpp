#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	int T;
	cin>>T;

	while(T--)
	{
		int num=0;
		int M,N,K;
		cin>>M>>N>>K;
		int map[50][50];
		for(int i=0;i<50;++i)
			for(int j=0;j<50;++j)
				map[i][j]=0;

		
		for(int j=0;j<K;++j)
		{
			int x;
			int y;
			cin>>x>>y;
			map[x][y]=1;
		}
		
		int result=0;
		
		while(true)
		{
			bool find=false;
			for(int i=0;i<M;++i)
			{
				for(int j=0;j<N;++j)
				{
					if(map[i][j]==1)
					{
						find=true;
						map[i][j]=2;
						result++;
						break;
					}
				}
				if(find==true)
					break;
			}
			
			if(find==false)
				break;
			
			bool extend;
			do
			{
				extend=false;
				for(int i=0;i<M;++i)
					for(int j=0;j<N;++j)
						if(map[i][j]==2)
						{
							if(i>0 && map[i-1][j]==1){ map[i-1][j]=2; extend=true; }
							if(i<M-1 && map[i+1][j]==1){ map[i+1][j]=2; extend=true; }
							if(j>0 && map[i][j-1]==1){ map[i][j-1]=2; extend=true; }
							if(j<N-1 && map[i][j+1]==1){ map[i][j+1]=2; extend=true; }
						}
			}
			while(extend==true);
			
		}
		v.push_back(result);
	}
	for(vector<int>::iterator iter=v.begin();iter<v.end();++iter)
	{
		cout<<*iter<<endl;
	}
}
