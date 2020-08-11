#include<bits/stdc++.h>
using namespace std;

int main()
{
	char roomnum[1000001];
	cin>>roomnum;
	vector<int> cntarr(10);
	double sixNnineCnt=0.0;
		
	int len=strlen(roomnum);
	for(int i=0;i<len;++i)
	{
		if(roomnum[i]=='6'||roomnum[i]=='9')
		{
			sixNnineCnt+=0.5;
		}
		else
		{
			cntarr[roomnum[i]-48]+=1;
		}
	}

	double maxsNn=0;
	if(sixNnineCnt==(int)sixNnineCnt)
	{
		maxsNn=sixNnineCnt;
	}
	else
	{
		maxsNn=int(sixNnineCnt)+1;
	}
	vector<int>::iterator iter;
	iter=max_element(cntarr.begin(),cntarr.end());

	cout<<max(*iter,(int)maxsNn);

}
