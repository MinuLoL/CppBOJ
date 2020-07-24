#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > v;
vector<pair<int,int> > cnts;

int main() {
	int N, start, end;
	cin>>N;

	for (int i = 0; i < N; i++) {
		cin>>start>>end;
		v.push_back(make_pair(end, start));
	}
	sort(v.begin(), v.end());
	cnts.push_back(v[0]);

	for (int i = 1; i < N; i++) {
		if (cnts[cnts.size() - 1].first <= v[i].second) cnts.push_back(v[i]);
	}
	
	cout << cnts.size();
	return 0;
}
