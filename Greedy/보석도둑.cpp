#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
p jew[300000];
int bag[300000];
int N,K,M,V,C;

int main()
{
	cin>>N>>K;
	for(int i=0;i<N;++i)
	{
		cin>>jew[i].first>>jew[i].second;
	}
	for(int i=0;i<K;++i)
	{
		cin>>bag[i];
	}
	sort(jew,jew+N);
	sort(bag,bag+K);
	
	long long sum=0;
	priority_queue<int> pq;
	for(int i=0,j=0;i<K;++i)
	{
		while(j<N&&jew[j].first<=bag[i])
			pq.push(jew[j++].second);
			
		if(!pq.empty())
		{
			sum+=pq.top();
			pq.pop();
		}
	}
	cout<<sum;
	return 0;
}
