#include<bits/stdc++.h>
using namespace std;

int main()
{
	char arr[8][8];
	int cnt=0;
	for(int i=0;i<8;++i)
	{
		cin>>arr[i];
	}
//	for(int i=0;i<8;++i)
//	{
//		for(int j=0;j<8;++j)
//		{
//			cout<<arr[i][j];
//		}
//		cout<<endl;
//	}
	for(int i=0;i<8;++i)
	{
		if(i%2==0)//¦�� ���ϋ� 
		{
			for(int j=0;j<8;++j)
			{
				if(j%2==0)//¦�� ���϶� 
				{ 
					if(arr[i][j]=='F')
					{
						cnt++;
					} 
				}
			 } 
		}
		else//Ȧ�� ���϶� 
		{
			for(int j=0;j<8;++j)
			{
				if(j%2==1)//Ȧ�� ���϶� 
				{
					if(arr[i][j]=='F')
					{
						cnt++;
					} 
				}
			 } 
		}
	}
	cout<<cnt; 
 } 
