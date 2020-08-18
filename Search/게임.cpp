#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long X,Y,Z;
	cin>>X;
	cin>>Y;
	Z=(Y*100)/X;
	if(Z>=99)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	long long first,last,mid,z;
	first=0;
	last=X;
	while(first<=last)
	{
		mid = (first + last) / 2;
		z = (Y + mid) * 100 / (X + mid);
		if (Z< z) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}
	cout<<first<<endl;
	return 0;
	
}
