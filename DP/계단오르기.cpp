#include<bits/stdc++.h>
using namespace std;
int n;
int step[301]={0,};
int d[301];
int dp(int x)
{
	
	if(x<1)return 0;
	if(d[x]!=0)return d[x];
	else if(x==1)
	{
		return d[x]=step[n];
	}
	else if(n>2&&x==2)
	{
		return d[x]=step[n];
	}
	else if(n==2&&x==2)
	{
		return d[x]=step[n-1]+step[n];
	}
	else if(x==3)
	{
		int a,b;
		a=step[n-2]+step[n];
		b=step[n-1]+step[n];
		return d[x]=max(a,b);
	}
	else if(n>4&&x==4)
	{
		int a,b;
		a=step[n-2]+step[n];
		b=step[n-3]+step[n-1]+step[n];

		return d[x]=max(a,b);
	}
	else if(n==4&&x==4)
	{
		int a,b,c;
		a=step[n-2]+step[n];
		b=step[n-3]+step[n-1]+step[n];
		c=step[n-3]+step[n-2]+step[n];
		return d[x]=max({a,b,c});
	}
	else if(x>=5&&x==n)
	{
		int e,f,g;
		e=step[n-x+2]+dp(x-2);
		f=step[n-x+1]+step[n-x+3]+dp(x-3);
		g=step[n-x+1]+step[n-x+2]+step[n-x+4]+dp(x-4);
		return d[x]=max({e,f,g});
	}
	else if(x>=5&&x<n)
	{
		int e,f;
		e=step[n-x+2]+dp(x-2);
		f=step[n-x+1]+step[n-x+3]+dp(x-3);

		return d[x]=max(e,f);
	}
}
int main()
{

	int num;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>num;
		step[i]=num;
	}
	cout<<dp(n);
	
	
}
