#include<bits/stdc++.h>
using namespace std;

int N;
int arr[500][500];
int d[500][500];
int dparr[500];

int dp(int x)
{
	if(x==1)
	{
		d[0][0]=arr[0][0];
		return d[0][0];
	}
	if(dparr[x]!=0)return dparr[x];
	else
	{
		for(int i=0;i<x;++i)
		{
			if(i==0)
			{
				d[x-1][i]=d[x-2][0]+arr[x-1][i]; //d[][]가 저장안
			}
			else if(i==x-1)
			{
				d[x-1][i]=d[x-2][x-1]+arr[x-1][i];
			}
			else
			{
				int a,b;
				a=arr[x-1][i]+d[x-2][i-1];
				b=arr[x-1][i]+d[x-2][i];
				d[x-1][i]=min(a,b);
			}
		}
		int maxnum=0;
		for(int i=0;i<x;++i)
		{
			if(maxnum<d[x-1][i])
				maxnum=d[x-1][i];
		}
		return dparr[x]=maxnum;
	}
	
	
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
	cout<<dp(N);
	
	
	
	
}
