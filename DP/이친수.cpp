#include<bits/stdc++.h>
using namespace std;
int d[90];
int dp(int x)//Ãß°¡µÈ °¹¼ö 
{
	if(x==1)return 0;
	if(x==2)return 1;
	if(x==3)return 2;
	if(d[x]!=0)return d[x];
	else
	{
		return d[x]=dp(x-2)+dp(x-1);
	}
}

int main()
{
	int N;
	cin>>N;
	
	int ans=0;
	for(int i=1;i<=N;++i)
	{
		ans+=dp(i);
	}
	cout<<ans;
}
