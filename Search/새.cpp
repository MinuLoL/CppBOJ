#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int i=1;
	int cnt=0;
	while(N>0)
	{
		if(N>=i)
		{
			N-=i;
			cnt++;
		}
		else
		{
			i=0;
		}
		i++;
	}
	cout<<cnt;
	
} 
