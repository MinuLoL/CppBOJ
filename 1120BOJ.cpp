#include<bits/stdc++.h>
using namespace std;

int main()
{
	char X[51]={};
	char Y[51]={};
//	int cntarr[51]={};
	int cnt=0;
	
	vector<int> v; 
	
	cin>>X>>Y;
	
	for(int j=0;j<=strlen(Y)-strlen(X);j++)
	{
		for(int i=0;i<strlen(X);++i)
		{
			if(X[i]!=Y[j+i])
			{
				cnt++;
			}
			
		}
//		cntarr[j]=cnt;
		v.push_back(cnt);
		cnt=0;
	}
	//���� cntarr�迭�߿� ���� ū �� ���ϱ�
	vector<int>::iterator iter;
	iter=min_element(v.begin(),v.end()); //max_element�� �ּҰ������� ���� ���� ã��
	 
	cout<<*iter;
	return 0;	
}
