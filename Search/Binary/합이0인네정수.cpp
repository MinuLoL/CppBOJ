#include<bits/stdc++.h>
using namespace std;
#define MAX 4001

long long AB[MAX*MAX];
long long CD[MAX*MAX];

int main()
{
	int A[MAX];
	int B[MAX];
	int C[MAX];
	int D[MAX];
	int N;
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>A[i]>>B[i]>>C[i]>>D[i];
	}
	int idx=0;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			AB[idx]=A[i]+B[j];
			CD[idx++]=(C[i]+D[j]);
		}
	}
	sort(CD,CD+N*N);

	long long cnt = 0;

    for (int i = 0; i < N * N; i++) {    // AB배열의 처음부터 N*N번째까지 BS로 쌍을 찾는다.
 
		auto range=equal_range(CD,CD+N*N,-AB[i]);
        cnt += range.second-range.first;

    }
    cout<<cnt;
    return 0;
}
