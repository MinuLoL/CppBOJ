#include<bits/stdc++.h>
using namespace std;
long long d[90];
long long dp(int x)//추가된 갯수 
{
	if(x==0)return 0;
	if(x==1)return 1;
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
	cout<<dp(N); 
}
