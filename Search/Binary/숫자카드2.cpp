#include<bits/stdc++.h>
using namespace std;

int N;
unordered_map<int,int>m1;
int M;
int arr[500000];
int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		int n;
		cin>>n;
		if(m1.find(n)==m1.end())
		{
			m1.insert({n,1});
		}
		else
		{
			auto iter=m1.find(n);
			iter->second++;
		}
	}
	cin>>M;
	for(int i=0;i<M;++i)
	{
		cin>>arr[i];
	}
//	for(auto iter=m1.begin();iter!=m1.end();iter++)
//	{
//		cout<<iter->first<<" "<<iter->second<<endl;
//	}
	for(int i=0;i<M;++i)
	{
		if(m1.find(arr[i])==m1.end())
			cout<<0<<" ";
		else
		{
			auto iter=m1.find(arr[i]);
			cout<<iter->second<<" ";
		}
	}
}

