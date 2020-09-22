#include<bits/stdc++.h>
using namespace std;

int N;
int Price[1001];
int dp[1001];


int main()
{
	cin>>N;
	for(int i=1;i<=N;++i)
	{
		cin>>Price[i];
	}
	dp[1]=Price[1];
	for(int i=1;i<=N;++i)
	{
		int maxnum=0;
		for(int j=1;j<=i;++j)
		{
			if(maxnum<dp[i-j]+dp[j])
				maxnum=dp[i-j]+dp[j];
		}
		dp[i]=max(maxnum,Price[i]);
	}
//	for(int i=1;i<=N;++i)
//	{
//		cout<<dp[i]<<" ";
//	}
	cout<<dp[N];
}
