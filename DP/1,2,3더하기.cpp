#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int d[10000];
int dp(int x)
{
	if(x<=0)return 0;
	if(x==1)return 1;
	if(x==2)return 2;
	if(x==3)return 4;
	
	if(d[x]!=0)return d[x];
	else
	{
		return d[x]=dp(x-1)+dp(x-2)+dp(x-3);
	}
}

int main()
{
	int T,n;
	cin>>T;
	for(int i=0;i<T;++i)
	{
		cin>>n;
		v.push_back(dp(n));
		
	}
	for(int i=0;i<T;++i)
	{
		cout<<v[i]<<endl;
	}
}



//DP를 이용하지 않은 코드
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> accv;
int factorial(int num) //팩토리얼 함수
{
	if(num<=1)return 1;
	
	return num*factorial(num-1);
}


int main()
{
	int arr[20][3];
	int T;
	int N;
	cin>>T;
	while(T!=0)
	{
		cin>>N;
		int nth=0;
		for(int i=0;i<(N/1+1);++i)    //x+2y+3z=N 을 성립하는 (x,y,z)구하기 (2차원배열)
		{
			for(int j=0;j<(N/2+1);++j)
			{
				for(int k=0;k<(N/3+1);++k)
				{
					if(i+2*j+3*k==N)
					{
						arr[nth][0]=i;
						arr[nth][1]=j;
						arr[nth][2]=k;
						nth++;
					}
				}
			}
		}	

		vector<int> v;
		int sum=0;
		int mo=1;
		for(int i=0;i<nth;++i)
		{
			for(int j=0;j<3;j++)
			{
				sum+=arr[i][j];
				mo*=factorial(arr[i][j]);
			}
			v.push_back(factorial(sum)/mo);
			sum=0;
			mo=1;
		}
//		cout<<accumulate(v.begin(),v.end(),0)<<endl;
		accv.push_back(accumulate(v.begin(),v.end(),0));
		v.erase(v.begin(),v.end());
		T--;
	}
	for(vector<int>::size_type i=0;i<accv.size();++i)
	{
		cout<<accv[i]<<endl;
	}

}
