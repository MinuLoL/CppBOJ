#include<bits/stdc++.h>
using namespace std;

int N,M;
int maxnum=1;

int main()
{
	cin>>N>>M;
	
	if(N>=3&&M>=7)
	{
		M-=6;
		maxnum+=4;
		if(M>=2)
		{
			maxnum+=M-1;
		}
//		maxnum+=M;
		
		
	}
	else//�湮�Ѱ��� 5���̻� �ɼ� ���� �� ��� 
	{
		if(N>=3)
		{
			if(M>=5)
			{
				maxnum+=3;
			}
			else
			{
				maxnum+=M-1;	
			} 
		}
		else if(N==2) //M�� ������ ���� �� 
		{
			if(M>=7)
			{
				maxnum+=3;
			}
			else
			{
				maxnum+=(M-1)/2;
			}
		}
		else if(N==1)//�̵��� �� ���� 
		{
		}
	}
	cout<<maxnum;

}
