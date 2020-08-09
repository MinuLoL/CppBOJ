#include<bits/stdc++.h>
using namespace std;


int main()
{
	char str[1000001];
	char search = ' ';
	int cnt=0;
	cin.getline(str,1000001);
	if(strlen(str)==1&&str[0]==' ')
	{
		cout<<0;
		return 0;
	}
	
	for(int i=1;i<strlen(str)-1;++i)
	{
		if(search==str[i])
			cnt++;
	 } 
	 
	 cout<<cnt+1;
	 return 0;
} 
