#include<bits/stdc++.h>
using namespace std;

int d[1000001];

int dp(int x)
{
	if(x==1)return 0;
	if(d[x]!=0)return d[x];
	
	if(x%3==0&&x%2==0)
	{
		int a,b,c;
		a=(dp(x/3)+1);
		b=(dp(x/2)+1);
		c=(dp(x-1)+1);
		
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		sort(v.begin(),v.end());
		return d[x]=v[0];
		
	}
	else if(x%3==0)
	{
		if(dp(x/3)+1>dp(x-1)+1)
		{
			return d[x]=(dp(x-1)+1);
		}
		else
			return d[x]=(dp(x/3)+1);
	}
	else if(x%2==0)
	{
		if(dp(x/2)+1>dp(x-1)+1)
		{
			return d[x]=(dp(x-1)+1);
		}
		else
			return d[x]=(dp(x/2)+1);
	}
	else if(x%3!=0&&x%2!=0)
	{
		return d[x]=dp(x-1)+1;	
	}	
}
	


int main()
{
	int n;
	cin>>n;
	cout<<dp(n);
}
