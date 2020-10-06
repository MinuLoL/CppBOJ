#include<bits/stdc++.h>
using namespace std;

#define MAX	51

vector<vector<int> > child_vec;	//�ڽĳ�带 �����ϴ� ���� 
int leaf_cnt=0,del_node;

void DFS(int now_node)
{
	if(del_node==now_node)	return;
	int ch_size=child_vec[now_node].size();
	switch(ch_size)
	{
		case 0:	//�ڽĳ�尡 0���϶� now_node�� ��������̹Ƿ� 1�����ְ� ���̿켱Ž���� 
			leaf_cnt++;return;
//			break;
		case 1:	//�ڽĳ�尡 1���϶� �� �ڽĳ�尡 del_node�� ������尡�Ǵ� 1�����ش� 
			if(child_vec[now_node][0]==del_node)
			{
				leaf_cnt++;return;
//				break;
			}
		default:	//ch_size�� 2�̻��϶� == �ڽĳ�尡 2�� �̻��϶� 
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
