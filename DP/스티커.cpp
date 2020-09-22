#include<bits/stdc++.h>
using namespace std;

int T,n;

int SecArr[2][100000]={0,};
int d[2][100000]={0,};
vector<int>v;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		
		
		for(int i=0;i<2;++i)
		{
			for(int j=0;j<n;++j)
			{
				cin>>SecArr[i][j];
			}
		}

		d[0][0]=SecArr[0][0];
		d[1][0]=SecArr[1][0];
		if(n>=2)
		{
			d[0][1]=SecArr[1][0]+SecArr[0][1];
			d[1][1]=SecArr[0][0]+SecArr[1][1];
			for(int i=2;i<n;++i)
			{
				d[0][i]=max(SecArr[0][i]+d[1][i-1],SecArr[0][i]+d[1][i-2]);
				d[1][i]=max(SecArr[1][i]+d[0][i-1],SecArr[1][i]+d[0][i-2]);
			}
			
			int maxnum=max(d[0][n-1],d[1][n-1]);
			v.push_back(maxnum);
		}
		
	}
	
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<endl;
	}
} 
