#include<bits/stdc++.h>
using namespace std;
int N;
int main()
{
	cin>>N;
	char str[N][101];
	int num=0;
	int rtncnt=0;
	for(int i=0;i<N;++i) //2���� �迭���� 
	{
		cin>>str[i];
	}
	
	for(int i=0;i<N;++i)	//�ܾ���ι������� ���� ���ĺ� cnt���ϴ� �� 
	{
		vector<char> v;
		int alphaCnt[26]={0,}; 
		int maxcnt=0;
		int len=strlen(str[i]);
//		cout<<"len: "<<len;
		for(int i=0;i<len;++i)
		{
			v.push_back(str[num][i]);
		}
		num++;
		vector<char>::iterator iter_end;
		iter_end=unique(v.begin(),v.end());		//������ ���ĺ��� �ϳ��� 
		
//		for(vector<char>::iterator iter=v.begin();iter!=iter_end;++iter)
//			cout<<*iter<<" ";
//		
		for(vector<char>::iterator iter=v.begin();iter!=iter_end;++iter)
		{
			int num=*iter-97;
			alphaCnt[num]++;
		}
//		for(int i=0;i<26;++i)
//		{
//			cout<<alphaCnt[i]<<" ";
//		}
//		cout<<endl;
		for(int i=0;i<26;++i)
		{
			if(alphaCnt[i]>maxcnt)
			{
				maxcnt=alphaCnt[i];
			}
		}
		if(maxcnt<2)
		{
			rtncnt++;
		}
		v.erase(v.begin(),v.end());	

	}
	cout<<rtncnt;

} 
