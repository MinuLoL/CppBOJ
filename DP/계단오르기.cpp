#include<bits/stdc++.h>
using namespace std;
int step[301]={0,};
int d[10000];
//int d[10000];
//
//int dp(int x)
//{
//	if(x==1)return 1;
//	if(x==2)return 2;
//	if(x==3)return 2;
//	if(x==4)return 4;
//	if(d[x]!=0)return d[x];
//	else
//	{
//		return d[x]=dp(x-2)+dp(x-3)+dp(x-4);
//	}
//}
int dp(int x)
{
	if(x==1)
	{
		return step[x];
	}
	if(x==2)
	{
		return step[x-1]+step[x];
	}
	if(x==3)
	{
		if((step[x-2]+step[x])>(step[x-1]+step[x-3]))
			return step[x-2]+step[x];
		else
			return step[x-1]+step[x];
	}
	if(x==4)
	{
		int a,b,c,d;
		a=step[x-3]+step[x-2]+step[x];
		b=step[x-3]+step[x-1]+step[x];
		c=step[x-2]+step[x-1]+step[x];
		d=step[x-2]+step[x];
		return max({a,b,c,d});
	}
	if(d[x]!=0)return d[x];
	else
	{
		
	}
	
}



int main()
{
	int n;
	int num;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>num;
		step[i]=num;
	}
	cout<<dp(n);
	
	
}
