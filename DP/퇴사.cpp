#include<bits/stdc++.h>
using namespace std;

int N; //1~15
int Time[16]; //1~5
int Price[16]; //1~1000
int d[16]={0,};
int da[16]={0,};
bool isInArr(int n,int t)
{
	if((n+t-1)>N)
		return false;
	else
		return true;
}



int main()
{
	cin>>N;
	for(int i=1;i<=N;++i)
	{
		cin>>Time[i]>>Price[i];
	}
	
	for(int i=N;i>=1;--i)
	{
		if(!isInArr(i,Time[i]))
		{
			da[i]=da[i+1];
			continue;
		}

		int sum=0;
		
		if(Time[i]>1)
		{
			for(int j=i+1;j<=i+Time[i]-1;++j)
			{
				sum+=d[j];
			}
		}
	
		if(Price[i]>=sum)
		{
			d[i]=Price[i];
			for(int j=i+1;j<=i+Time[i]-1;++j)
			{
				d[j]=0;
			}
			da[i]=Price[i]+da[i+Time[i]];
		}
		else
		{
			da[i]=da[i+1];
			continue;
		}
	}
	
	
//	cout<<"d[i]:";
//	for(int i=1;i<=N;++i)
//	{
//		cout<<d[i]<<" ";
//	}
//	cout<<endl;
//	cout<<"da[i]:";
//	for(int i=1;i<=N;++i)
//	{
//		cout<<da[i]<<" ";
//	}
//	cout<<endl;
	
	int max=0;
	for(int i=1;i<=N;++i)
	{
		if(max<da[i])
			max=da[i];
	}
	cout<<max;
//	int sum=0;
//	for(int i=1;i<=N;++i)
//	{
//		sum+=d[i];
//	}
//	cout<<sum;
	return 0;
}
