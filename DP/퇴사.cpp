#include<bits/stdc++.h>
using namespace std;

int N;
int Time[16]={0,};
int Price[16]={0,};
int dp[16]={0,};

int main()
{
	cin>>N;
	for(int i=1;i<=N;++i)
	{
		cin>>Time[i]>>Price[i];
	}
	for(int i=N;i>=1;--i)
	{
		int nextpos=i+Time[i];
		if(nextpos>N+1)
		{
			dp[i]=dp[i+1];
		}
		else
		{
			dp[i]=max(dp[i+1],dp[nextpos]+Price[i]);
		}
	}
//	for(int i=1;i<=N;++i)
//	{
//		cout<<dp[i]<<" ";
//	}
	cout<<dp[1];
	return 0;
	
}
