#include<bits/stdc++.h>
using namespace std;
int T;
long long d[101];
vector<long long>v;
 
long long dp(int x)
{
	if(x==1)return 1;
	if(x==2)return 1;
	if(x==3)return 1;
	if(d[x]!=0)return d[x];
	return d[x]=dp(x-2)+dp(x-3);
}

int main()
{
	cin>>T;
	for(int i=0;i<T;++i)
	{
		int num;
		cin>>num;
		v.push_back(dp(num));		
	}
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}
