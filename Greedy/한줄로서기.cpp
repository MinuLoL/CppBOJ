#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin>>N;
	
	vector<int> v(N);
	vector<int> height(N);
	for(int i=0;i<N;++i)
	{
		cin>>v[i];
	}

	for(int i=0;i<N;++i)
	{
		int cnt=-1;
		for(int j=0;j<N;++j)
		{
			if(height[j]==0)
			{
				cnt++;
			}
			if(cnt==v[i])
			{
				height[j]=i+1;
				break;
			}
		}
		
	}
	for(int i=0;i<N;++i)
	{
		cout<<height[i]<<" ";
	}
	
	
}
