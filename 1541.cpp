#include<bits/stdc++.h>
using namespace std;

int main()
{
	char line[51]={};
	cin>>line;
	int sum=0;
	int strlength=strlen(line);
	char checkplusidx[strlength]={};
	char checkminusidx[strlength]={};
	
	int checking=0;
	int num=0;
	for(int i=0;i<strlength;++i)
	{
		if(line[i]=='+')
		{
			checkplusidx[num++]=(i+1)+'0';
		}
		if(line[i]=='-')
		{
			checking=i;
			break;
		}
	}
	int num2=0;
	for(int i=checking;i<strlength;++i)
	{
		if(line[i]=='+'||line[i]=='-')
		{
			checkminusidx[num2++]=(i+1)+'0';
		}
	}
	sum=atoi(&line[0]);
	
	for(int i=0;i<strlen(checkplusidx);++i)
	{
		sum+=atoi(&line[checkplusidx[i]-'0']);
	}
	for(int i=0;i<strlen(checkminusidx);++i)
	{
		sum-=atoi(&line[checkminusidx[i]-'0']);
	}
	
	cout<<sum<<endl;
	
	return 0;

}
