#include<bits/stdc++.h>
using namespace std;

int N;
int arr[500][500];
int d[500][500];
vector<int> v;

int dp(int x,int y)//x는 갯수(N) y는 열  
{
	if(d[x][y]!=0)return d[x][y];
	if(x==0)return arr[0][0];
	else
	{
		if(y==0)
		{
			return d[x][y]=dp(x-1,0)+arr[x][y]; //d[][]가 저장안
		}
		else if(y==x)
		{
			return d[x][y]=dp((x-1),(x-1))+arr[x][y];
		}
		else
		{
			int a,b;
			a=arr[x][y]+dp((x-1),(y-1));
			b=arr[x][y]+dp((x-1),(y));
			return d[x][y]=max(a,b);
		}
	}

}


int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<=i;++j)
		{
			cin>>arr[i][j];
		}
	}


	for(int i=0;i<N;++i)
	{
		for(int j=0;j<=i;++j)
		{
			dp(i,j);
		}
	}
	for(int i=0;i<N;++i)
	{
		v.push_back(dp(N-1,i));
	}
	vector<int>::iterator iter;
	iter=max_element(v.begin(),v.end());
	cout<<*iter<<endl;
	
}
