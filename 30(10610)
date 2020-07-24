#include<bits/stdc++.h>
using namespace std;

int main()
{
	char N[100001]={0,};
	cin>>N;
	vector<int>v;
	int strlennum=strlen(N);
	
	for(int i=0;i<strlennum;++i)
	{
		v.push_back(N[i]-'0');
	}
//	for(vector<int>::size_type i=0;i<v.size();++i)
//		cout<<v[i]<<" ";
//	cout<<endl;
	sort(v.begin(),v.end(),greater<int>());
	
	int cnt=count(v.begin(),v.end(),0);
//	cout<<"cnt: "<<cnt<<endl;
	if(cnt==0) //0이 하나이상존재하는지 검사 
	{
		cout<<"-1";
		return 0;
	}
	else	//원소들의 합이 3의 배수인지 검사 
	{
		int accnum=accumulate(v.begin(),v.end(),0);
		if(accnum%3==0)
		{
			for(vector<int>::size_type i=0;i<v.size();++i)
				cout<<v[i];
		}
		else
		{
			cout<<"-1";
			return 0;
		}
	}
	
	return 0;
}
