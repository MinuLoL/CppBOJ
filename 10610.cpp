#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<int>v;

	int len = 0;
    int i = 1;
    while (N > i) {	//자릿수구하기 
        i *= 10;
        len++;
    }
	int num=len-1;
	for(int i=0;i<len;++i) 
	{
		v.push_back(N/pow(10,(num)));
		N-=v[i]*pow(10,(num));
		--num;
	}
	
//	for(vector<int>::size_type i=0;i<v.size();++i)
//		cout<<v[i]<<" ";
//	cout<<endl;
	sort(v.begin(),v.end(),greater<int>());
	int n=count(v.begin(),v.end(),0);
	if(n==0) //0이 하나이상존재하는지 검사 
	{
		cout<<"-1";
		return 0;
	}
	else	//원소들의 합이 3의 배수인지 검사 
	{
		
	}
	
	return 0;
}
