#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int main()
{
	int N;
	int weight;
	int max_weight=0;
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>weight;
		v.push_back(weight);
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < N; i++) {
		weight = v[i] * (N - i);
		if (max_weight < weight)
			max_weight = weight;
	}
	cout<<max_weight;
	return 0;
}
