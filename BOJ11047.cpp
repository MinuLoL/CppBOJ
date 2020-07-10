#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v;

	int PersonNum;
	int time;
	int tsum=0;
	int result=0;
	int Parr[1000];
//	cout<<"몇명이 줄서있습니까?"<<endl;
	cin>>PersonNum;
//	cout<<"사람마다 걸리는 사람 입력"<<endl;
	for(vector<int>::size_type i=0;i<PersonNum;++i)
	{
		cin>>time;
		v.push_back(time);
	}
	
	sort(v.begin(),v.end());
	
//	for(vector<int>::iterator iter=v.begin();iter!=v.end();++iter)
//		cout<<*iter<<" ";
//	cout<<endl;
//	
	for(int i=0;i<PersonNum;++i)
	{
		tsum+=v[i];
		Parr[i]=tsum;
	}
	
	for(int i=0;i<PersonNum;++i)
	{
		result+=Parr[i];
	}
	cout<<result;
	return 0;

}
