#include<bits/stdc++.h>
using namespace std;

int N,S;
int arr[100000];
vector<int>len;

int main()
{
	cin>>N>>S;
	for(int i=0;i<N;++i)
	{
		cin>>arr[i];
	}
	int start=0;
	int end=0;
	int sum=arr[0];
	while(end<N)
	{
		if(sum<S)
		{
			end++;
			sum+=arr[end];
		}
		else		
		{
			len.push_back(end-start+1);
			sum-=arr[start];
			start++;
		}
		
	}
	vector<int>::iterator iter;
	
	
	iter=min_element(len.begin(),len.end());
	if(!len.empty())
	{
		cout<<*iter;
	}
	else
	{
		cout<<0;
	}

	return 0;
	
			
}
