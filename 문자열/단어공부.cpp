#include<bits/stdc++.h>
using namespace std;


int main()
{
	char word[1000001]; //��ҹ��ڷ� ������ ���ĺ�
	int alphaCnt[26]={0,}; //�迭 ���� ��� 0���� �ʱ�ȭ
	int maxnum=0; 
	int maxcnt=0;
	int maxpos=0;
	cin>>word;
	int x=strlen(word); 
	for(int i=0;i<x;++i) //100���� ���ư����ϴ� �ð��ʰ� 
	{
		int num;
		if(word[i]<=90) //�빮���ϰ�� 
		{
			num=word[i]-65;
		}
		else			//�ҹ����ϰ�� 
		{
			num=word[i]-97;
		}
		++alphaCnt[num];
	}
	for(int i=0;i<26;++i) //�ִ� ���� ã�� 
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
