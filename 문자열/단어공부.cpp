#include<bits/stdc++.h>
using namespace std;


int main()
{
	char word[1000001]; //대소문자로 구성된 알파벳
	int alphaCnt[26]={0,}; //배열 원소 모두 0으로 초기화
	int maxnum=0; 
	int maxcnt=0;
	int maxpos=0;
	cin>>word;
	int x=strlen(word); 
	for(int i=0;i<x;++i) //100만번 돌아가야하니 시간초과 
	{
		int num;
		if(word[i]<=90) //대문자일경우 
		{
			num=word[i]-65;
		}
		else			//소문자일경우 
		{
			num=word[i]-97;
		}
		++alphaCnt[num];
	}
	for(int i=0;i<26;++i) //최대 갯수 찾기 
	{
		if(alphaCnt[i]>maxnum)
		{
			maxnum=alphaCnt[i];
		}
	}
	for(int i=0;i<26;++i)
	{
		if(alphaCnt[i]==maxnum)
		{
			maxcnt++;
			maxpos=i;
		}
		
	}
	if(maxcnt>1)
	{
		cout<<"?";
		return 0;
	}
	else
	{
		cout<<char(maxpos+65);
	}
	
	
		
}
