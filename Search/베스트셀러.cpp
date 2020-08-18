#include<bits/stdc++.h>
using namespace std;
int N;
int main()
{
	cin>>N;
	int cnt=0;

	vector<string> v(N);
	vector<string> vcopy(N);
	for(int i=0;i<N;++i)
	{
		cin>>v[i];
	}
	
	//vcopy에 복사 
	vector<string>::iterator iter1;
	iter1=copy(v.begin(),v.end(),vcopy.begin());
	
	//v배열 정렬(사전편찬순)후 유니크함수 
	sort(v.begin(),v.end());
	vector<string>::iterator iter_end;
	iter_end=unique(v.begin(),v.end());
	
	//unique함수적용된 배열수 구하기 
	for(vector<string>::iterator iter=v.begin();iter!=iter_end;++iter)
	{	
		cnt++;//책의 종류수 
	}

	//갯수를 기록한 배열생성 
	vector<int> cntarr(cnt);
	for(int i=0;i<cnt;++i)
	{
		string s=v[i];
		for(vector<string>::size_type j=0;j<vcopy.size();++j)
		{
			if(s==vcopy[j])
			{
				cntarr[i]+=1;
			}
		}
	}
	vector<int>::iterator iter2;
	iter2=max_element(cntarr.begin(),cntarr.end());
	for(int i=0;i<cnt;++i)
	{
		if(cntarr[i]==*iter2)
		{
			cout<<v[i];
			return 0;
		}
	}	
}
