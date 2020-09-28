#include<bits/stdc++.h>
using namespace std;

long long S;
long long sum=0;
long long cnt=1;

int main()
{
	cin>>S;
	while(1)
	{
		sum+=cnt;
		if(sum>S)
		{
			cnt--;
			break;
		}
		cnt++;
	}
	cout<<cnt;
	return 0;
} 
