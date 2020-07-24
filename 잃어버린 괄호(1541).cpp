#include<bits/stdc++.h>
using namespace std;

int main()
{
	char line[51]={0,};
	int pidx[50]={0,};
	int midx[50]={0,};
	int pnum=0;
	int mnum=0;
	
	cin>>line;
	for(int i=0;i<strlen(line);++i)
	{
		if(line[i]=='+')
		{
			pidx[pnum++]=i+1;
		}
		else if(line[i]=='-')
		{
			for(;i<strlen(line);++i)
			{
				if(line[i]=='+'||line[i]=='-')
				{
					midx[mnum++]=i+1;
				}
			}
			break;
		}
	}
	int sum=atoi(&line[0]);
	for(int i=0;i<pnum;++i)
	{
		sum+=atoi(&line[pidx[i]]);
	}
	for(int i=0;i<mnum;++i)
	{
		sum-=atoi(&line[midx[i]]);
	}
	cout<<sum;
	return 0;
	
}
