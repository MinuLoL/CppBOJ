#include<bits/stdc++.h>
using namespace std;
int N,L;
vector<int> v;
int GetMynum(int x)
{
	int ret=x;
	for(int i=0;i<L-1;++i)
	{
		ret+=++x;
	}
	return ret;
}

int main()
{
	cin>>N;//18
	cin>>L;//2
	int minnum=0;
	int mnum=N/L;//9
	int retcnt=0;

	while(mnum>=0)
	{
		int cnt=L;
		minnum=GetMynum(mnum); //9+10 , 8+9 , 7+8, 6+7 ,5+6
//		cout<<"minnum:"<<minnum<<endl;
		while(minnum<N)
		{
			minnum+=mnum+cnt;
			cnt++;
		}
		if(minnum==N)
		{
			for(int i=0;i<cnt;++i)
			{
				v.push_back(mnum++);
			}
			for(int i=0;i<cnt;++i)
			{
				cout<<v[i]<<" ";
			}
			return 0;
		}
		else if(cnt>100)
		{
			cout<<"-1";
			return 0;
		}
		else
		{	
			mnum--;
		}
	}
	cout<<"-1";

}
