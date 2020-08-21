#include<bits/stdc++.h>
using namespace std;
vector<int> v;

int GetA(int t)
{
	if(t>=300)
	{
		return t/300;
	}
	else
		return 0;
} 
int GetB(int t)
{
	if(t>=60)
	{
		return t/60;
	}
	else
	{
		return 0;
	}
}
int GetC(int t)
{
	if(t>=10)
	{
		return t/10;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int T;//요리시간 
	cin>>T; //(1<=T<=10000)
	v.push_back(GetA(T));
	T-=GetA(T)*300;
	v.push_back(GetB(T));
	T-=GetB(T)*60;
	v.push_back(GetC(T));
	T-=GetC(T)*10;
	
	if(T!=0)
	{
		cout<<-1<<endl;
		return 0;
	}
	else
	{
		for(int i=0;i<3;++i)
		{
			cout<<v[i]<<" ";
		}
		return 0;
	}
	
			
}
