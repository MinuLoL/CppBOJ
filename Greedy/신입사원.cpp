#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v;
vector<int> cntv; 
bool cmpfirst(const pair<int , int> &a, const pair<int , int> &b)
{
	return a.first>b.first;
}

int main()
{
	int T; //���̽� �� 
	int N; //������ ��
	int cnt=0;  
	int realcnt=0;
	cin>>T;
	
	for(int i=0;i<T;++i)
	{
		cin>>N;
		for(int j=0;j<N;++j)
		{
			int fscore,sscore;
			cin>>fscore>>sscore;
			v.push_back(make_pair(fscore,sscore));
		}
		//�ִ� �������ο��� ���ؾߴ�
		sort(v.begin(),v.end(),cmpfirst);
		 
		for(int k=0;k<v.size();++k)
		{
//		 	for(int l=k+1;l<v.size();++l) //�ð��ʰ�!! ���� count_if()�Լ���... 
//		 	{
//		 		if(v[k].second>=v[l].second)
//		 		{
//		 			cnt++;
//		 			break; 
//				}
//			}


			if(cnt==1)
			{
				realcnt++;	
			}
			cnt=0;
		}
//		cout<<v.size()-realcnt<<endl;  //�̺κи� ����(�ذ�Ϸ�) 
		cntv.push_back(v.size()-realcnt); 
		 
		realcnt=0;
		v.erase(v.begin(),v.end());
	}
	for(int i=0;i<cntv.size();++i)
	{
		cout<<cntv[i]<<endl;
	}
	
	return 0;
}
