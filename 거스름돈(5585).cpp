#include<bits/stdc++.h>
using namespace std;

int main()
{
	int price;
	int cnt=0;
	cin>>price;
	vector<int>v;
	v.push_back(500);
	v.push_back(100);
	v.push_back(50);
	v.push_back(10);
	v.push_back(5);
	v.push_back(1);
	int remain=1000-price;
	for(vector<int>::size_type i=0;i<v.size();++i)
	{
		if(remain>=v[i])
		{
			cnt+=remain/v[i];
			remain=remain%v[i];
		}
	}
	cout<<cnt;
	return 0;
}
