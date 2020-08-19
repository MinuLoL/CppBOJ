#include<bits/stdc++.h>
using namespace std;

int main()
{
	char str[2501];
	char ScStr[51];
	cin.getline(str,2501);
	cin.getline(ScStr,51);
	
	int realcnt=0;
	int Strlen=strlen(str);
	int Sclen=strlen(ScStr);
	
	for(int i=0;i<=Strlen-Sclen;++i)
	{
		int cnt=0;
		for(int j=0;j<Sclen;++j)
		{
			if(str[i+j]!=ScStr[j])
			{
				break;
			}
			else
				cnt++;
		}

		if(cnt==Sclen)
		{
			realcnt++;
			if(i+Sclen<Strlen)
			{
				i=i+Sclen-1;
			}
			else
				break;
		}
	}
	
	cout<<realcnt;
	
}
