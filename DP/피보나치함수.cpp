#include<bits/stdc++.h>
using namespace std;

//int fibonacci(int n)
//{
//	if(n==0)
//	{
//		cout<<"0";
//		return 0;
//	}
//	else if(n==1)
//	{
//		cout<<"1";
//		return 1;
//	}
//	else
//	{
//		return fibonacci(n-1)+fibonacci(n-2);
//	}
//}
int df[10000];
int	ds[10000];

int dpf(int x)
{
	if(x==0)return 1;
	if(x==1)return 0;
	if(df[x]!=0)return df[x];
	else
	{
		return df[x]=dpf(x-1)+dpf(x-2);
	}
}
int dps(int y)
{
	if(y==0)return 0;
	if(y==1)return 1;
	if(ds[y]!=0)return ds[y];
	else
	{
		return ds[y]=dps(y-1)+dps(y-2);
	}
}

int main()
{	
	int T,n;
	int arr[1000][2];
	cin>>T;
	for(int i=0;i<T;++i)
	{
		cin>>n;
		arr[i][0]=dpf(n);
		arr[i][1]=dps(n);
	}
	for(int i=0;i<T;++i)
	{
		cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
	}
	return 0;
}
