#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v;
	
	int N;
	int K;
	int mok[11]={0,};
	int kindofCoin;
	int sum=0;
	cin>>N>>K;
	for(vector<int>::size_type i=0;i<N;i++)
	{
		cin>>kindofCoin;
		v.push_back(kindofCoin);
	}
	sort(v.begin(),v.end(),greater<int>());//³»¸²Â÷¼ø Á¤·Ä ex>50000 10000 5000 1000 ....

	for(int i=0;i<v.size();++i)
	{
		if(0<K/v[i])
		{
			mok[i]=K/v[i];
			K-=(K/v[i])*v[i];
		}
		else
			mok[i]=0;

	} 

	for (int i = 0; i <= N - 1; i++) {
		sum += mok[i];
	}
	cout<<sum;
	return 0;
	
	
	
	

}
