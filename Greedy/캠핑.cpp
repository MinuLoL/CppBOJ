#include<bits/stdc++.h>
using namespace std;

int L,P,V;
vector<int> l;
vector<int> p;
vector<int> v;
int main()
{
	int testcnt=0;
	while(1)
	{
		cin>>L>>P>>V;
		
		if(L==0&&P==0&&V==0)
		{
			break;
		}
		testcnt++;
		l.push_back(L);
		p.push_back(P);
		v.push_back(V);
	}	
	int n=testcnt;
	while(testcnt--)
	{
		int index=n-testcnt;
		int maxday=	(v[index-1]/p[index-1])*l[index-1];
		if(v[index-1]%p[index-1]<=l[index-1])
		{
			maxday+=v[index-1]%p[index-1];
		}
		else
		{
			maxday+=l[index-1];
		}
		cout<<"Case "<<index<<": "<<maxday<<endl;
	}
	
} 
