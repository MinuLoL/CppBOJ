#include<bits/stdc++.h>
using namespace std;

void swap(char *arr)
{
	int x;
	x=arr[0];
	arr[0]=arr[2];
	arr[2]=x;
}

int main()
{
	char fnum[4];
	char scnum[4];
	cin>>fnum;
	cin>>scnum;
	
	swap(fnum);
	swap(scnum);
	
	int n1=stoi(&fnum[0]);
	int n2=stoi(&scnum[0]);
	cout<<max(n1,n2);
	return 0;
}
