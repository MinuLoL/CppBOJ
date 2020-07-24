#include<bits/stdc++.h>
using namespace std;



int main()
{
	int N,M,K;
	cin>>N>>M>>K;
	int wn;
	int mn;
	int cnt;
	int num;
	if((N/2)<=M)
	{
		wn=(N/2)*2;
		cnt+=N-wn; //짝수가되면서 없어진 수  1or0 
		
		mn=N/2;
		cnt+=M-mn; //N의 절반값이되면서 없어진 수 
		
		if(K<=cnt)
		{
			cout<<mn;
			return 0;
		}	
		else
		{
			K-=cnt;
			if(K%3==0)
			{
				num=K/3;
			}
			else
			{
				num=K/3+1;
			}
			cout<<mn-num;
			return 0;
		}
	}
	else
	{
		wn=2*M;
		cnt=N-wn; //줄어든 여자 수
		
		mn=M;
		
		if(K<=cnt)
		{
			cout<<mn;
			return 0;
		}
		else
		{
			K-=cnt;
			if(K%3==0)
			{
				num=K/3;
			}
			else
			{
				num=K/3+1;
			}
			cout<<mn-num;
			return 0;
		}
		 
	}
	
	return 0;
	
	
}
