#include<bits/stdc++.h>
using namespace std;

int N,M;
int maps[8][8];

int main()
{
	cin>>N>>M;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			cin>>maps[i][j];
		}
	}
	//combination(조합)으로 0인 위치마다 pair로 배열에 저장해서 그 갯수만큼 조합(ex) 1,2,3 / 1,2,4 / 1,2,5 .....)이렇게 위치한곳에 1이란 벽을 세워서 2(바이러스) 인곳을 찾아
	//BFS를 시도해서 바이러스가 최소로 퍼지게하는 수를 구하면 답이 나올듯 하다
	
	

}
