#include<bits/stdc++.h>
using namespace std;
int d[90];
int dp(int x)//추가된 갯수 
{
	if(x==1)return 1;
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
	cout<<dp(N); 
}
