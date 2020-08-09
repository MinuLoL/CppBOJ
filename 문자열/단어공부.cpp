#include<bits/stdc++.h>
using namespace std;

vector<int>alphanum(26);

int main()
{

	char s[1000001];
	cin>>s;
//	for(int i=0;i<26;++i)
//	{
//		alphanum.push_back(0);
//	}
	for(int i=0;i<strlen(s);++i)
	{
		int num;
		if(s[i]<=90)
		{
			num=s[i]-65;
		}
		else
		{
			num=s[i]-97;
		}
		++alphanum[num];
	}
	
	
	vector<int>::iterator iter;
	iter=max_element(alphanum.begin(),alphanum.end());	
	int maxnum=*iter;
	
	int n=count(alphanum.begin(),alphanum.end(),maxnum);
	if(n>1)
	{
		cout<<'?';
		return 0;
	}
	int max=0;
	int maxpos;
	for(int i=0;i<alphanum.size();++i)
	{
		if(alphanum[i]>max)
		{
			max=alphanum[i];
			maxpos=i;
		}
	}
	cout<<char(maxpos+65);
	
	
	
}
