#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v;
vector<int> cntv;
bool cmpfirst(const pair<int , int> &a, const pair<int , int> &b)
{
	return a.first<b.first;
}

int main()
{
	int T; //케이스 수 
	int N; //참가자 수
	int cnt=0;  
	int realcnt=0;
	cin>>T;
	int stand=0;
	int cmppivot=1;
	for(int i=0;i<T;++i)
	{
		cin>>N;
		for(int j=0;j<N;++j)
		{
			int fscore,sscore;
			cin>>fscore>>sscore;
			v.push_back(make_pair(fscore,sscore));
		}
		//최대 참가자인원수 구해야댐
		sort(v.begin(),v.end(),cmpfirst);
		vector<int> vsecond;	


		for(int i=0;i<v.size();++i) //정렬된 뒷자리 배열입력 
		{
			vsecond.push_back(v[i].second);
		}
	
		while(cmppivot<v.size())
		{
			if(vsecond[stand]<vsecond[cmppivot])
			{
				cnt++;
				cmppivot++;
			}
			else if(vsecond[stand]>vsecond[cmppivot])
			{
				stand=cmppivot;
				cmppivot++;
			}
		}	

		cntv.push_back(v.size()-cnt); 
		 
		cnt=0;
		stand=0;
		cmppivot=1;
		v.erase(v.begin(),v.end());
		vsecond.erase(vsecond.begin(),vsecond.end());
	}
	for(int i=0;i<cntv.size();++i)
	{
		cout<<cntv[i]<<endl;
	}
	
	return 0;
}
