#include<bits/stdc++.h>
using namespace std;

int K,N;
long long arr[10000];
long long maxnum=0;
long long getnum(long long x)
{
	long long sum=0;
	for(int i=0;i<K;++i)
	{
		sum+=arr[i]/x;
	}
	return sum;
}

long long search(long long start,long long end)
{
	if(start>end) return maxnum;
	long long mid=(start+end)/2;
	if(getnum(mid)>=N)
	{
		if(maxnum<mid)
			maxnum=mid;
		return search(mid+1,end);
	}
	else
	{
		return search(start,mid-1);
	}
}


int main()
{
	cin>>K>>N;
	for(int i=0;i<K;++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+K);
	cout<<search(1,arr[K-1]);
}
