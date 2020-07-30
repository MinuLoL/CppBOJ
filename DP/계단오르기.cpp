#include<bits/stdc++.h>
using namespace std;
int n;
int step[300]={0,};
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
		return step[n-1];
	}
	if(n>2&&x==2)//이 부분 수정필요
	{
		return step[n-1];
	}
	if(n==2&&x==2)
	{
		return step[n-2]+step[n-1];
	}
	if(x==3)
	{
		if((step[n-3]+step[n-1])>(step[n-2]+step[n-1]))
			return step[n-3]+step[n-1];
		else
			return step[n-2]+step[n-1];
	}
	if(n==4&&x==4)
	{
		int a,b,c;
		a=step[n-4]+step[n-2]+step[n-1];
		b=step[n-3]+step[n-1];
		c=step[n-4]+step[n-3]+step[n-1];
		return max({a,b,c});
	}
	if(n>4&&x==4)
	{
		int a,b;
		a=step[n-4]+step[n-2]+step[n-1];
		b=step[n-3]+step[n-1];
		return max({a,b});
	}
	else
	{
		int e,f,g;
		e=step[n-x+1]+dp(x-2);
		f=step[n-x]+step[n-x+2]+dp(x-3);
		g=step[n-x]+step[n-x+1]+step[n-x+3]+dp(x-4);
		return max({e,f,g});
	}
	
}



int main()
{

	int num;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>num;
		step[i]=num;
	}
	cout<<dp(n);
	
	
}
