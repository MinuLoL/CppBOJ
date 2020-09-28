#include<bits/stdc++.h>
using namespace std;

int N;
int arr[10000];
int budget;
int maxnum=0;

int getsum(int maxnumber)
{
	int sum=0;
	for(int i=0;i<N;++i)
	{
		if(arr[i]>maxnumber)
		{
			sum+=maxnumber;
		}
		else
		{
			sum+=arr[i];
		}
	}
	return sum;
}

int search(int start,int end,int budget)
{
	int mid=(start+end)/2;
	if(start>end)return maxnum;
	
	if(getsum(mid)==budget) return mid;
	else if(getsum(mid)<budget)
	{
		if(maxnum<mid)
			maxnum=mid;
		return search(mid+1,end,budget);
	} 
	else if(getsum(mid)>budget)
	{
		return search(start,mid-1,budget);
	}
	
}


int main()
{
	cin>>N;
	int sum=0;
	for(int i=0;i<N;++i)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr,arr+N,greater<int>());
	cin>>budget;
	
	if(budget>=sum)
	{
		cout<<arr[0];
	}
	else
	{
		cout<<search(1,arr[0],budget);
	}
	
}
