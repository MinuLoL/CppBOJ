#include<bits/stdc++.h>
using namespace std;
int d[10]={0,1,1,1,1,1,1,1,1,1};
int arr[10];
int N;
#define mod	1000000000;
long long sum=0;
long long dp(int n)
{	
	if(n==1)
	{
		for(int i=0;i<10;++i)
		{
			sum+=d[i];
		}
		return sum;
	}
	else
	{
		for(int j=0;j<n-1;++j)
		{
			arr[0]=d[1];
			arr[9]=d[8];
			for(int i=1;i<9;++i)
			{
				arr[i]=(d[i-1]+d[i+1])%mod; //!!!!!
			}
			for(int i=0;i<10;++i)
			{
				d[i]=arr[i];
			}		
		}
		

		for(int i=0;i<10;++i)
		{
			sum+=(d[i]);
		}
		return sum%mod;	//!!!!!
	}
}


int main()
{
	cin>>N;
	cout<<dp(N);
}
