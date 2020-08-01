#include<bits/stdc++.h>
using namespace std;

int N;
int arr[500][500];
int d[500][500];


int dp(int x,int y)//x는 갯수(N) y는 열  
{
	if(x==1)return arr[0][0];
	if(d[x][y]!=0)return d[x][y];
	else
	{
		if(y==0)
		{
			return d[x-1][y]=dp(x-1,0)+arr[x-1][y]; //d[][]가 저장안
		}
		else if(y==x-1)
		{
			return d[x-1][y]=dp((x-1),(x-1))+arr[x-1][y];
		}
		else
		{
			int a,b;
			a=arr[x-1][y]+dp((x-1),(y-1));
			b=arr[x-1][y]+dp((x-1),(y));
			return d[x-1][y]=min(a,b);
		}
	}
//		int maxnum=0;
//		for(int i=0;i<x;++i)
//		{
//			if(maxnum<d[x-1][i])
//				maxnum=d[x-1][i];
//		}
//		return dparr[x]=maxnum;
}


int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<=i;++j)
		{
			cin>>arr[i][j];
		}
	}
	dp(1,0);
	dp(2,0);
	dp(2,1);
	dp(3,0);
	dp(3,1);
	dp(3,2);


	
	cout<<dp(3,1);
	
	
	
}
