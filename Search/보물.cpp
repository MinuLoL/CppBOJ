#include<bits/stdc++.h>
using namespace std;

int main()
{
//	int arr[50];
	int N;
	cin>>N;
	vector<int> A;
	vector<int> B;
//	vector<int> BCopy(N);
	for(int i=0;i<N;++i)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	for(int i=0;i<N;++i)
	{
		int x;
		cin>>x;
		B.push_back(x);
	}
//	vector<int>::iterator iter;
//	iter=copy(B.begin(),B.end(),BCopy.begin());
	sort(A.begin(),A.end());
	sort(B.begin(),B.end(),greater<int>());
//	sort(BCopy.begin(),BCopy.end(),greater<int>());
//	
//	for(int i=0;i<N;++i)
//	{
//		for(int j=0;j<N;++j)
//		{
//			if(B[j]==BCopy[i])
//			{
//				arr[j]=A[i];
//				break;
//			}
//		}
//	}
	int sum=0;
	for(int i=0;i<N;++i)
	{
		sum+=A[i]*B[i];
	}
	
	cout<<sum;
	
}
