#include<bits/stdc++.h>
using namespace std;

int N,M;
int Arr[100000]={0,};
int Snum[100000]={0,};

int search(int start,int end,int target)
{
	if(start>end) return 0;
	int mid=(start+end)/2;
	
	if(Arr[mid]==target)return 1;
	else if(Arr[mid]>target)return search(start,mid-1,target);
	else return search(mid+1,end,target);
}
int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>Arr[i];
	}
	sort(Arr,Arr+N);
	cin>>M;
	for(int i=0;i<M;++i)
	{
		cin>>Snum[i];
	}
	
	for(int i=0;i<M;++i)
	{
		cout<<search(0,N-1,Snum[i])<<'\n'; 	//endl은 출력량이 많을때 속도 저하시킴 
	}

}
