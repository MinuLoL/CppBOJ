#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
	multimap<int,int> mm;
	int N;
	int first,second;
	cin>>N;
	int cnt;
	int maxnum;
	vector<int> cntv;
	for(int i=0;i<N;++i)//key값 기준으로 오름차순 정렬 
	{
		cin>>first>>second;
		mm.insert(pair<int,int>(first,second));
	}
	multimap<int,int>::iterator iter=mm.begin();
	multimap<int,int>::iterator iter_check;
	multimap<int,int>::iterator iter_pos;
//	for(iter=mm.begin();iter!=mm.end();++iter)  //원소 잘입력됬는지 확인(이상 없음) 
//	{
//		cout<<iter->first<<' '<<iter->second<<endl;
//	}
	for(;iter!=mm.end();++iter)
	{
		cnt=1;
		iter_pos=iter;
		iter_check=iter;
		++iter_check;
		cout<<iter->first<<' '<<iter->second<<endl;
		cout<<iter_check->first<<' '<<iter_check->second<<endl;
		for(;iter_check!=mm.end();++iter_check)
		{
			if(iter->second<iter_check->first)
			{
				iter=iter_check;
				++iter_check;
				cnt++;
				cout<<"cnt!!: "<<cnt<<endl;
			}
			else if(iter->second==iter_check->first)
			{
				iter=iter_check;
				++iter_check;
				cnt++;
				cout<<"cnt!!: "<<cnt<<endl;
				cout<<"!!!"<<endl;
			}			
		}
		cout<<"cnt:"<<cnt<<endl;
		cntv.push_back(cnt);
		iter=iter_pos;
	}

	maxnum=cntv[0];
	for(vector<int>::size_type i=0;i<cntv.size();++i)
	{
		if(cntv[i]>maxnum)
			maxnum=cntv[i];
	}

	cout<<maxnum;
	return 0;
}
