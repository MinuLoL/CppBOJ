#include<bits/stdc++.h>
using namespace std;

int d[100000];
int n;
int arr[100001];
int dp(int x)
{
	if(d[x-1]!=0)return d[x-1];
	
	int sum=0;
	int max=arr[x];
	for(int i=x;i<=n;++i)
	{
		sum+=arr[i];
		if(max<=sum)
		{
			max=sum;
		}
	}
	return d[x-1]=max;
}




int main()
{

	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;++i)
	{
		dp(i);
	}
	int max=d[0];
	for(int i=1;i<n;++i)
	{
		if(max<d[i])
			max=d[i];
	}
	cout<<max;
	
}
