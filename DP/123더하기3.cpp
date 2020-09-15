#include<bits/stdc++.h>
using namespace std;

vector<long long> v;
long long d[1000001];
const long long MOD = 1000000009;
long long dp(int x)
{
	if(x==1)return 1;
	if(x==2)return 2;
	if(x==3)return 4;
	
	if(d[x]!=0)return d[x];
	else
	{
		return d[x]=(dp(x-1)+dp(x-2)+dp(x-3))%MOD;
	}
}

int main()
{
	int T,n;
	cin>>T;
	for(int i=0;i<T;++i)
	{
		cin>>n;
		v.push_back(dp(n));
		
	}
	for(int i=0;i<T;++i)
	{
		cout<<v[i]<<endl;
	}
}
