#include<bits/stdc++.h>
using namespace std;
int cost[1000][3]={0,};
int dp[1000][3]={0,};

int RGB(int n)
{
	dp[0][0]=cost[0][0];
	dp[0][1]=cost[0][1];
	dp[0][2]=cost[0][2];
	for(int i=1;i<n;++i)
	{
		dp[i][0]=cost[i][0]+min(dp[i-1][1],dp[i-1][2]);
		dp[i][1]=cost[i][1]+min(dp[i-1][0],dp[i-1][2]);
		dp[i][2]=cost[i][2]+min(dp[i-1][0],dp[i-1][1]);
	}
	return min({ dp[n-1][0],dp[n-1][1],dp[n-1][2] });
}

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<3;++j)
		{
			cin>>cost[i][j];
		}
	}

	cout<<RGB(N);
	return 0;
	
	
	//RGB(N) -> 
	
	
}
