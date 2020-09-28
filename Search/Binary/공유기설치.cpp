#include<bits/stdc++.h>
using namespace std;

int N,C;
int arr[200000];
int maxgap;

bool possible(int gap)
{
	int count=C-1;
	int num=arr[0];
	
	for(int i=1;i<N;++i)
	{
		if(num+gap<=arr[i])
		{
			count--;
			num=arr[i];
		}
		if(count<=0)
			return true;
	}
	
	return false;
	
}

int search(int start,int end)
{
	
	int mid=(start+end)/2;
	if(start>end)return maxgap;
	
	if(possible(mid))
	{
		if(maxgap<mid)
			maxgap=mid;
		return search(mid+1,end);
	}
	else
	{
		return search(start,mid-1);
	}
	
}



int main()
{
	cin>>N>>C;
	for(int i=0;i<N;++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+N);
	
	cout<<search(1,arr[N-1]-arr[0]);
}
