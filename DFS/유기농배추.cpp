#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	int M,N,K;
	int cnt=0;
	vector<int> cntarr;
	for(int i=0;i<T;++i)
	{
		vector<pair<int,int>> arr; //1�� �Էµ� ��ǥ
		cin>>M>>N>>K;
		vector<vector<int>> v(M,vector<int>(N,0));

		for(int j=0;j<K;++j)
		{
			int x;
			int y;
			cin>>x>>y;
			v[x][y]=1;
		}

		for(int i=0;i<M;++i)
		{
			for(int j=0;j<N;++j)
			{
				if(v[i][j]==1)
				{
					arr.push_back(make_pair(i,j)); //1�� �Էµ� ��ǥ�� ���ʴ�� ����
				}
			}
		}
//		
//		for(int i=0;i<K;++i)
//		{
//			cout<<arr[i].first<<" "<<arr[i].second<<endl;
//		}
		for(int k=0;k<K;++k)
		{
			int x=arr[k].first;
			int y=arr[k].second;
			if(x==M-1&&y!=N-1) //�� �Ʒ����϶��� ������ ĭ�� �˻�
			{
				if(v[x][y+1]==1)
				{
					v[x][y]=0;
				 } 
			}
			else if(y==N-1&&x!=M-1) //�� ���������϶��� �Ʒ�ĭ�� �˻�
			{
				if(v[x+1][y]==1)
				{
					v[x][y]=0;
				}
			}
			else if(x==M-1&&y==N-1) //�� ������ĭ�϶��� �˻� ����
			{}
			else                     //�����ʰ� �Ʒ�ĭ�� �˻�
			{
				if(v[x][y+1]==1||v[x+1][y]==1)
				{
					v[x][y]=0;
				}
			}
		}
		cnt=0;
		for(int i=0;i<K;++i)    //1�� �Էµ� ��ǥ�� ���ƴٴϸ� 1�� ���� ����
		{
			int x=arr[i].first;
			int y=arr[i].second;
			if(v[x][y]==1)
			{
				cnt++;
			}
		}
		cntarr.push_back(cnt);
//      for(int i=0;i<M;++i)
//		{
//			for(int j=0;j<N;++j)
//			{
//				cout<<v[i][j]<<" ";
//			}
//			cout<<endl;
//		}
	}
	for(int i=0;i<T;++i)
	{
		cout<<cntarr[i]<<endl;
	}
	
}
