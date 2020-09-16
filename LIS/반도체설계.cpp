#include<bits/stdc++.h>
using namespace std;

vector<int> lis;
int arr[40000];
int N;
int ans=0;
int main()
{
	lis.push_back(-1);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];	
	}	
	
	lis.push_back(-1);
	 for (int i = 0; i < N; ++i) {

        if (arr[i] > lis.back()) {
            lis.push_back(arr[i]);
            ans++;
        }

        else {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout<<ans;
}

