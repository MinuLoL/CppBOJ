#include<bits/stdc++.h>
using namespace std;

int N;
char words[10][9];
int alphaEV[26]={0,};
vector<int> v;
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
	for(int i=0;i<N;++i)
	{
		cin>>words[i];
	}
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<strlen(words[i]);++j)
		{
			alphaEV[(int)words[i][j]-65]+=multiten(strlen(words[i])-j-1);
		}		
	}
	for(int i=0;i<26;++i)
	{
		if(alphaEV[i])
			v.push_back(alphaEV[i]);
	}
	sort(v.begin(),v.end(),greater<int>());
//	for(int i=0;i<v.size();++i)
//	{
//		cout<<v[i]<<" ";
//	}
	int num=9;
	int sum=0;
	for(int i=0;i<v.size();++i)
	{
		for(int j=0;j<26;++j)
		{
			if(alphaEV[j]==v[i])
			{
				sum+=(num--)*v[i];
				break;
			}
		}
	}
	cout<<sum;
}
