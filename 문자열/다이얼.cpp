#include<bits/stdc++.h>
using namespace std;

int main()
{
	char str[16];
	cin>>str;
	int x=strlen(str);
	int sum=0;
	for(int i=0;i<x;++i)
	{
		if(str[i]>=65&&str[i]<=67)
		{
			sum+=2;
		}
		else if(str[i]>=68&&str[i]<=70)
		{
			sum+=3;
		}
		else if(str[i]>=71&&str[i]<=73)
		{
			sum+=4;
		}
		else if(str[i]>=74&&str[i]<=76)
		{
			sum+=5;
		}
		else if(str[i]>=77&&str[i]<=79)
		{
			sum+=6;
		}
		else if(str[i]>=80&&str[i]<=83)
		{
			sum+=7;
		}
		else if(str[i]>=84&&str[i]<=86)
		{
			sum+=8;
		}
		else
		{
			sum+=9;
		}
	}
	cout<<x+sum;
} 
