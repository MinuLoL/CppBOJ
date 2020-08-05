#include<bits/stdc++.h>
using namespace std;
int v[10001]={0,};
int d[10001]={0,};

int dp(int x)
{
	if(x<=0)return 0;
	if(x==1)return v[1];
	if(x==2)return v[1]+v[2];
	if(d[x]!=0)return d[x];
	else
	{
		d[x]=max({dp(x-3)+v[x]+v[x-1],dp(x-2)+v[x],dp(x-1)});
		return d[x];
	}
}
	
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>v[i];
	}
	
	cout<<dp(n);
	return 0;
}
