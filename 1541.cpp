#include<bits/stdc++.h>
using namespace std;

int main()
{
	char line[50]={};
	int pmidx[50]={};
	cin>>line;
	int num=0;
	for(int i=0;i<strlen(line);++i)
	{
		if(line[i]=='+'||line[i]=='-')
		{
			pmidx[num++]=i;
		}
	}
//	for(int i=0;i<num;++i) num은 pmidx배열의 갯수 
//		cout<<pmidx[i]<<" ";
//	cout<<endl;
	int firstminusidx=0; 
	for(int i=0;i<strlen(line);++i)
	{
		if(line[i]=='-')
		{
			firstminusidx=i;
		}
	}
//	cout<<firstminusidx;
	int sum=atoi(&line[0]);
	int ck=0;
	for(int i=0;i<num;++i)
	{
		if(pmidx[i]==firstminusidx)
		{
			ck=	i; //2
			break;
		}
	}

	for(int i=0;i<ck;++i)
	{
		sum+=atoi(&line[pmidx[i]]);
	}
	for(int i=ck;i<num;++i)
	{
		sum-=atoi(&line[pmidx[i]+1]);
	}
	cout<<sum;
	return 0;
	
}
