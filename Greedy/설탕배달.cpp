#include<bits/stdc++.h>
using namespace std;
int darr[5000]={0,};

int GetF(int n)
{
	if(n%5==0)
	{
		return n/5;
	}
	else
	{
		while(n>=0)
		{
			n-=3;
			if(n%5==0)
			{
				return n/5;
			}
		}
		return -1;
	}
	
	
}
int GetTh(int n)
{
	int cnt=0;
	if(n%5==0)
	{
		return 0;
	}
	while(n>=0)
	{
		n-=3;
		cnt++;
		if(n%5==0)
		{
			return cnt;
		}
	}
	return -1;
}

int dp(int n)
{
	int Fcnt=GetF(n);
	int Thcnt=GetTh(n);
	if(n==0)return darr[n]=0;
	if(Fcnt==-1||Thcnt==-1)
	{
		return darr[n]=-1;
	}
	if(darr[n]!=0)return darr[n];
	else
	{
		return darr[n]=Fcnt+Thcnt;
	}
}

int main()
{
	int N;
	cin>>N;
	cout<<dp(N);
}
