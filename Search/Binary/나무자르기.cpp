#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<int> v;
int maxnum;
int maxtarget;

long long getlen(int tn)
{
	long long sum=0;
	for(int i=0;i<v.size();++i)
	{
		if(v[i]>tn)
		{
			sum+=(v[i]-tn);
		}	
	}
	return sum;	
}

int search(int start,int end,int targetlen)
{
	if(start>end)return maxtarget;
	int mid=(start+end)/2;
//	cout<<"mid: "<<mid<<endl;
//	cout<<"getlen(mid):"<<getlen(mid)<<endl;
	if(getlen(mid)==targetlen)return mid;
	else if(getlen(mid)<targetlen)return search(start,mid-1,targetlen);
	else
	{
		if(getlen(mid)<getlen(maxtarget))
			maxtarget=mid;
//		cout<<"maxtarget:"<<maxtarget<<endl;
		return search(mid+1,end,targetlen);
	}
}


int main()
{
	cin>>N>>M;
	for(int i=0;i<N;++i)
	{
		int num;
		cin>>num;
		v.push_back(num);
	}
	vector<int>::iterator iter;
	iter=max_element(v.begin(),v.end());
	maxnum=*iter;

	cout<<search(1,maxnum,M);
	
}
