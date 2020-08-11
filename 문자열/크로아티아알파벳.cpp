#include<bits/stdc++.h>
using namespace std;

int main()
{
	char word[101];
	cin>>word;
	int wCnt=0;
	int len=strlen(word);
	for(int i=0;i<len;++i)
	{
		if(word[i]=='c'){
			if(word[i+1]=='='||word[i+1]=='-')
			{
				wCnt++;
				i+=1;
			}
			else{
				wCnt++;	
			}
		}
		else if(word[i]=='d')
		{
			if(word[i+1]=='z'&&word[i+2]=='=')
			{
				wCnt++;
				i+=2;
			}
			else if(word[i+1]=='-')
			{
				wCnt++;
				i+=1;
			}
			else{
				wCnt++;	
			}
		}
		else if(word[i]=='l'||word[i]=='n')
		{
			if(word[i+1]=='j')
			{
				wCnt++;
				i+=1;
			}
			else{
				wCnt++;	
			}
		}
		else if(word[i]=='s'||word[i]=='z')
		{
			if(word[i+1]=='=')
			{
				wCnt++;
				i+=1;
			}
			else{
				wCnt++;	
			}
			
		}
		else
		{
			wCnt++;
		}
		
	}
	cout<<wCnt;
	
	
}
