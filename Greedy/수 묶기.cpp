#include<bits/stdc++.h>
using namespace std;

int N;
int pcnt=0;
int mcnt=0;
int onecnt=0;
int sum=0;
vector<int> parr;
vector<int> marr;
vector<int> onearr;
int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		int num;
		cin>>num;
		if(num<=0)//음수면 
		{
			marr.push_back(num);
			mcnt++;
		}
		else if(num>1)
		{
			parr.push_back(num);
			pcnt++;
		}
		else if(num==1) //1인경우에는 곱해주기 보다 그냥 더하는게 최대가된다 
		{
			onearr.push_back(num);
			onecnt++;	
		}
	}
	
	sort(parr.begin(),parr.end(),greater<int>());
	sort(marr.begin(),marr.end(),less<int>());
//	
//	for(int i=0;i<parr.size();++i)
//	{
//		cout<<parr[i]<<" ";
//	 } 
//	cout<<endl;
//	for(int i=0;i<marr.size();++i)
//	{
//		cout<<marr[i]<<" ";
//	}
//	
	//parr와 marr의 양수,음수 일때
	for(int i=0;i<(pcnt/2);++i)
	{
		sum+=parr[i*2]*parr[i*2+1];
	}
	if(pcnt%2==1)
	{
		sum+=parr[pcnt-1];
	}
	for(int i=0;i<(mcnt/2);++i)
	{
		sum+=marr[i*2]*marr[i*2+1];	
	}
	if(mcnt%2==1)
	{
		sum+=marr[mcnt-1];
	}
	sum+=onecnt;
	cout<<sum;
}
