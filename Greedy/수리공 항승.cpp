#include<bits/stdc++.h>
using namespace std;

int N,L;
int leakpos[1001];
bool taped[1001];
int tapenum=0;
int main()
{
	cin>>N>>L;
	for(int i=0;i<N;++i)
	{
		cin>>leakpos[i];
	}
	sort(leakpos,leakpos+N);
//	for(int i=0;i<N;++i)
//	{
//		cout<<leakpos[i]<<" ";
//	}
	for(int i=0;i<N;++i)
	{
		if(!taped[leakpos[i]])
		{
			tapenum++;
			for(int j=leakpos[i];j<=L-1+leakpos[i];++j)
			{
				taped[j]=true;
			}
		}
//		else
//			continue;
	}
	cout<<tapenum;
}
