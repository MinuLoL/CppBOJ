#include<bits/stdc++.h>
using namespace std;

int N;
int dp[1001];
int arr[1001];
int lis_dp(int n){ // dp를 이용한 lis algorithm
    int i,j;
    int max = 1;
    for(i=0;i<n;i++){
        dp[i] = 1;
        for(j=0;j<i;j++){
            if(arr[j] < arr[i] && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
                
				//최대 길이 나올때 마다 갱신 
				if(max < dp[i]){
                    max = dp[i];
                }
            }
        }
    }
    return max;
}

int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>arr[i];
	}

	cout<<lis_dp(N);

}
