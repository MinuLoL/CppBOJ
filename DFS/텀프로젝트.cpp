#include<bits/stdc++.h>
using namespace std;

#define MAX	100001

int n;	//학생 수
int wantarr[MAX];	//같이 팀을 하고싶은 학생
bool visited[MAX];	//방문했는지 확인하는 배열
bool pass[MAX];		//더이상 방문하지 않을것을 확신하는 경우(방문했더라도 다시 방문할 경우가있어서)
int cnt;		//팀을 이루는 학생 수
vector<int>v;		//cnt를 저장하는 v

void DFS(int num)	
{
	visited[num]=true;	//방문한 학생이면 다시 확인할 필요없음
	
	int next=wantarr[num];	//num이 가리키는 학생=next
	
	if(!visited[next])	//가리키는 학생을 방문한적이 없다면
		DFS(next);	//가리키는 학생으로 이동
	
	else if(!pass[next])	//방문한적이 있으나 다시 체크할 가능성 있다면
	{
		for(int i=next;i!=num;i=wantarr[i])	//사이클을 이루는 학생수 추가
			cnt++;
		cnt++;					//자기 자신추가
	}
	pass[num]=true;	//더이상 방문하지 않을것을 확신하는 학생(사이클을 이루지않는 학생은 elseif문통과)
}

void init()	//배열,cnt 초기화
{
	cnt=0;
	memset(visited,false,sizeof(visited));
	memset(pass,false,sizeof(pass));
}

int main()
{
	int Testcase;
	cin>>Testcase;
	while(Testcase--)
	{
		init();
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>wantarr[i];
		}
		for(int i=1;i<=n;++i)
		{
			if(!visited[i])
				DFS(i);
		}
		v.push_back(n-cnt);	//팀을 꾸리지 못한 학생들 수
	}
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}
