#include<bits/stdc++.h>
using namespace std;

long long d[91];
long long dp(int n)
{
	if(n==0)return 0;
	if(n==1)return 1;
	if(d[n]!=0)return d[n];
	else
	{
		return d[n]=dp(n-2)+dp(n-1);
	}
} 
 
 int main()
 {
 	int n;
 	cin>>n;
 	cout<<dp(n);
 }
