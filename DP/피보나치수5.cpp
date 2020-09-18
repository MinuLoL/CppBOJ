#include<bits/stdc++.h>
using namespace std;

int n;
int d[21];
int fibonacci(int x)
{
	if(x==0)return 0;
	if(x==1)return 1;
	if(d[x]!=0)return d[x];
	return d[x]=fibonacci(x-1)+fibonacci(x-2);
}


int main()
{
	cin>>n;
	cout<<fibonacci(n);
}
