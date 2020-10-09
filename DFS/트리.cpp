#include<bits/stdc++.h>
using namespace std;

#define MAX	51

vector<vector<int> > child_vec;	//자식노드를 저장하는 벡터 
int leaf_cnt=0,del_node;

void DFS(int now_node)
{
	if(del_node==now_node)	return;
	int ch_size=child_vec[now_node].size();
	switch(ch_size)
	{
		case 0:	//자식노드가 0개일때 now_node가 리프노드이므로 1더해주고 깊이우선탐색끝 
			leaf_cnt++;return;
//			break;
		case 1:	//자식노드가 1개일때 그 자식노드가 del_node면 리프노드가되니 1더해준다 
			if(child_vec[now_node][0]==del_node)
			{
				leaf_cnt++;return;
//				break;
			}
		default:	//ch_size가 2이상일때 == 자식노드가 2개 이상일때 
				for(int ch_idx=0;ch_idx<ch_size;ch_idx++)
					DFS(child_vec[now_node][ch_idx]);
				break;
	}
}

int main()
{
	int N,root;
	cin>>N;
	
	child_vec.resize(N);
	
	for(int in_idx=0;in_idx<N;++in_idx)
	{
		int parent;
		cin>>parent;
		if(parent!=-1)
			child_vec[parent].push_back(in_idx);
		else
			root=in_idx;
	}
	cin>>del_node;
	DFS(root);
	cout<<leaf_cnt;
	return 0;
}
