#include<bits/stdc++.h>
using namespace std;

int N,k;

int main()
{
	cin>>N>>k;
	
	int start=1,end=k;
	int ans;
	
	while(start<=end)
	{
		long long cnt=0;
		int mid=(start+end)/2;
		for(int i=1;i<=N;++i)
		{
			cnt+=min((mid/i),N);
		}
		if(cnt<k)
			start=mid+1;
		else
		{
			ans=mid;
			end=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
