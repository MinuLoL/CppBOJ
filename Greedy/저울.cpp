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
//���� ���� �ø����� �������� ���԰� ���ݱ��� �ø�
//�������� �� ��+1 ���� Ŀ���� ���� �������� �� ��+1�� ������ �� ���� �ּҰ�
//�� �ȴ�. 
