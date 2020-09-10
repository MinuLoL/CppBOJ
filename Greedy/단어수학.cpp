#include<bits/stdc++.h>
using namespace std;

int N;
char words[10][9];
int wordlen[10];
int alphabet[26]={0,}; //A~Z
int nums[10][9];
int usedcnt[26]={0,}; 
int multiten(int n)
{
	int retnum=1;
	if(n==0)
	{
		return 1;
	}
	for(int i=0;i<n;++i)
	{
		retnum*=10;
	}
	return retnum;
}
int main()
{
	cin>>N;
	int max=0;
	int inputnum=9;
	for(int i=0;i<N;++i)
	{
		cin>>words[i];
		wordlen[i]=strlen(words[i]);
		if(max<wordlen[i])
		{
			max=wordlen[i];
		}
	}
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<strlen(words[i]);++j)
		{
			int k=(int)words[i][j]-65;
			usedcnt[k]++;
		}
	}
//	while(max>=0)
//	{
//		for(int i=0;i<N;++i)
//		{
//			cout<<"wordlen[i]:"<<wordlen[i]<<endl;
//			cout<<"max:"<<max<<endl;
//			if(wordlen[i]==max)
//			{
//				cout<<"index:"<<i<<endl;
//				cout<<"!"<<words[i][strlen(words[i])-max]<<endl;
//				int k=(int)words[i][strlen(words[i])-max]-65;
//				cout<<"k:"<<k<<endl;
//				if(alphabet[k])
//				{
//					nums[i][strlen(words[i])-max]=alphabet[k];
//					wordlen[i]--;
//					continue;
//				}
//				alphabet[k]=inputnum;
//				
//				nums[i][strlen(words[i])-max]=inputnum;
//				wordlen[i]--;
//				inputnum--;
//
//			}
//		}
//		
//		max--;
//	}
	for(int i=0;i<26;++i)
	{
		cout<<alphabet[i]<<" ";
	}
	cout<<endl;
	
//	for(int i=0;i<N;++i)
//	{
//		for(int j=0;j<9;++j)
//		{
//			cout<<nums[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int sum=0;
	for(int i=0;i<N;++i)
	{
		for(int j=strlen(words[i])-1;j>=0;--j)
		{	
		
//			cout<<nums[i][j]*multiten(strlen(words[i])-j-1)<<endl;
			sum+=nums[i][j]*multiten(strlen(words[i])-j-1);
		}
	}
	cout<<sum;
	
}
