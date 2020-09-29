#include<bits/stdc++.h>
using namespace std;

int N;
int A[4000];
int B[4000];
int C[4000];
int D[4000];

vector<long long> v1;
vector<long long> v2;

int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>A[i]>>B[i]>>C[i]>>D[i];
	}
	
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			v1.push_back(A[i]+B[j]);
			v2.push_back((C[i]+D[j])*(-1));
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
//	for(int i=0;i<v1.size();++i)
//	{
//		cout<<v1[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=0;i<v1.size();++i)
//	{
//		cout<<v2[i]<<" ";
//	}
//	cout<<endl;
	//투포인터를 활용
	int start1=0;
	int start2=0;
	int cnt=0;
	int pos;
	while(start2<=(N*N)&&start1<=(N*N))
	{
		if(v1[start1]>v2[start2])
		{
			start2++;
		}
		else if(v1[start1]<v2[start2])
		{
			start1++;
		}
		else
		{
			pos=start2;
			while(v1[start1]==v2[pos])
			{
				cnt++;
				pos++;
			}
			start1++;

		}
	}
	cout<<cnt;
}
