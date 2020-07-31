#include<bits/stdc++.h>
using namespace std;
int N;
int arr[500][500];
int d[500][100000000000];
vector<int> v;

int dp(int x)
{
	if(x==1)return arr[0][0];
	else
	{
		
	}
	
}



int main(void)
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<=i;++j)
		{
			cin>>arr[i][j];
		}
	}

	cout<<dp(N);
	
}
