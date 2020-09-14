#include<bits/stdc++.h>
using namespace std;

int N;
int arr[1000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N,less<int>());

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (sum + 1 < arr[i]) break;
		sum += arr[i];
	}
	cout << sum + 1 << endl;
	return 0;
}
//만약 현재 올리려는 저울추의 무게가 지금까지 올린
//저울추의 총 합+1 보다 커지는 순간 저울추의 총 합+1이 측정할 수 없는 최소값
//이 된다. 
