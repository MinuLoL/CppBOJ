#include<bits/stdc++.h>
using namespace std;

int N;
int sarr[500000];
int M;
int carr[500000];

int search(int start,int end,int target)
{
	if(start>end)return 0;
	int mid=(start+end)/2;
	
	if(sarr[mid]==target)return 1;
	else if(sarr[mid]>target)return search(start,mid-1,target);
	else return search(mid+1,end,target);
}



int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>sarr[i];
	}
	sort(sarr,sarr+N);
	cin>>M;
	for(int i=0;i<M;++i)
	{
		cin>>carr[i];
	}
	
	for(int i=0;i<M;++i)
	{
		cout<<search(0,N-1,carr[i])<<" ";
	}
}
