#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	
	cin>>N;
	long long int num;
	for(long long int i=666;;++i)
	{
		vector<int>v;
		num=i;
		int size=0;
		while(num!=0)
		{
			v.push_back(num%10);
			num=num/10;
			size++;
		}
		for(int j=0;j<size-2;++j)
		{
			if(v[j]==6)
			{
				if(v[j]==v[j+1]&&v[j+1]==v[j+2])
				{
					
					N--;
					if(N==0)
					{
						cout<<i;
						return 0;
					}
					break;
				}
			}
		}	
	}
	return 0;
	
	
}
