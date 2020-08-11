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
		if(i%2==0)//Â¦¼ö ÇàÀÏ‹š 
		{
			for(int j=0;j<8;++j)
			{
				if(j%2==0)//Â¦¼ö ¿­ÀÏ¶§ 
				{ 
					if(arr[i][j]=='F')
					{
						cnt++;
					} 
				}
			 } 
		}
		else//È¦¼ö ÇàÀÏ¶§ 
		{
			for(int j=0;j<8;++j)
			{
				if(j%2==1)//È¦¼ö ¿­ÀÏ¶§ 
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
