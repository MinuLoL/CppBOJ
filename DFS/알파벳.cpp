#include <iostream>
#include <algorithm>
using namespace std;
 
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
 
int R,C;
int ans=0;
char maps[20][20];
int alphabet[26]={0,}; //A~Z
 
void dfs(int y,int x,int cnt){
    
    ans=max(ans,cnt);
    
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        
        if(ny<0 || ny>=R || nx<0 || nx>=C)
            continue;
        
        //A:65 Z:90
        int k=(int)maps[ny][nx]-65;
        if(alphabet[k])
            continue;
        
        alphabet[k]++;
        dfs(ny,nx,cnt+1);
        alphabet[k]--;
        
    }
}
int main(){
    
    cin>>R>>C;
    
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++){
            cin>>maps[i][j];
        }
 
    alphabet[(int)maps[0][0]-65]++; //(0,0)���� �湮 üũ
    dfs(0,0,1);
    
    cout<<ans<<endl;
    
    return 0;
}

