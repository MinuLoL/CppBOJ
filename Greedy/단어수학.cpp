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

	while(max)
	{
		for(int i=0;i<N;++i)
		{
			if(wordlen[i]==max)
			{
				int k=(int)words[i][strlen(words[i])-max]-65;
				int count=0;
				if(alphabet[k])
				{
					nums[i][strlen(words[i])-max]=alphabet[k];
					wordlen[i]--;
					continue;
				}
				for(int j=i+1;j<N;++j)
				{
					if(usedcnt[k]<usedcnt[(int)words[j][strlen(words[j])-max]-65])
						count++;
				}
				alphabet[k]=inputnum-count;
				
				nums[i][strlen(words[i])-max]=inputnum-count;
				wordlen[i]--;
				if(count==0)
				{
					inputnum--;
				}

			}
		}
		
		max--;
	}

	int sum=0;
	for(int i=0;i<N;++i)
	{
		for(int j=strlen(words[i])-1;j>=0;--j)
		{	
			sum+=nums[i][j]*multiten(strlen(words[i])-j-1);
		}
	}
	cout<<sum;
	
}
