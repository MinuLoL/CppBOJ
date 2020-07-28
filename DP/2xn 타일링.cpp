#include<bits/stdc++.h>
using namespace std;
int d[10000];
int dp(int x)
{
	if(x==1)return 1;
	if(x==2)return 2;
	if(d[x]!=0)return d[x];
	else
	{
		return d[x]=(dp(x-1)+dp(x-2))%10007;
	}
}

int main()
{
	int n;
	cin>>n;
	cout<<dp(n);
} 
