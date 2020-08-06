#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int dp[100000]; 

int dpFunc(int x)
{
	if(x==0)return dp[x]=arr[x];
	if(dp[x]!=0)return dp[x];
	else
	{
		return dp[x]=max(arr[x]+dpFunc(x-1),arr[x]);
	}
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>arr[i];
	}
	dpFunc(n-1);
//	for(int i=0;i<n;++i)
//	{
//		cout<<"dp["<<i<<"]: "<<dp[i]<<endl;
//	}
	
	//dp배열 중 가장 큰 수 찾아서 출력
	int max=-1000;
	for(int i=0;i<n;++i)
	{
		if(max<=dp[i])
			max=dp[i];
	}
	cout<<max;
	return 0; 
	
}
