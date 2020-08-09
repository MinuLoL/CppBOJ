#include<bits/stdc++.h>
using namespace std;
int alphabet[27]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};




int main()
{
	char s[101]; //소문자로만 이뤄진 단어
	cin>>s;
	for(int i=0;i<strlen(s);++i)
	{
		int num=s[i]-97;
		if(alphabet[num]==-1)
		{
			alphabet[num]=i;
		}
	}
	for(int i=0;i<26;++i)
	{
		cout<<alphabet[i]<<" ";
	}
	
}
