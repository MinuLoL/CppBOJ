#include<bits/stdc++.h>
using namespace std;
int n;
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
		return step[n];
	}
	if(x==2)//이 부분 수정필요
	{
		return step[n];
	}
	if(x==3)
	{
		if((step[n-2]+step[n])>(step[n-1]+step[n]))
			return step[n-2]+step[n];
		else
			return step[n-1]+step[n];
	}
	if(x==4)
	{
		int a,b;
		a=step[n-3]+step[n-1]+step[n];
		b=step[n-2]+step[n];
		return max({a,b});
	}
	if(d[x]!=0)return d[x];
	else// 이부분수정필요
	{
		int e,f,g;
		e=step[n-x+2]+dp(x-2);
		f=step[n-x+1]+step[n-x+3]+dp(x-3);
		g=step[n-x+1]+step[n-x+2]+step[n-x+4]+dp(x-4);
		return max({e,f,g});
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
