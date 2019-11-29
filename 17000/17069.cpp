#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long int ll;

int n,board[33][33];
ll dp[4][33][33];
int nxt[4][4]={{},{1,3,-1},{2,3,-1},{1,2,3,-1}};
int sz[4] = {0,1,1,3};
int dx[4][3] = {{},{1},{0},{1,0,1}};
int dy[4][3] = {{},{0},{1},{1,1,0}};
bool inMap(int y,int x){
    return y>=0&&x>=0&&y<n&&x<n;
}
ll dfs(int y,int x,int type){
    ll& ret = dp[type][y][x];
    //cout<<y<<" "<<x<<" : "<<type<<" "<<ret<<endl;
    if(ret!=-1) return ret;
    if(y==n-1&&x==n-1) return ret=1;
    ret=0;
    for(int i=0;nxt[type][i]!=-1;i++){
        int ntype = nxt[type][i];
        bool canMove = true;
        for(int j=0;j<sz[ntype];j++){
            int Y = y+dy[ntype][j];
            int X = x+dx[ntype][j];
            if(!inMap(Y,X) || board[Y][X]){
                canMove = false;
                continue;
            }
        }
        //cout<<"----"<<(canMove?"can ":"can't ")<<ntype<<endl;
        if(canMove) ret += dfs(y+dy[ntype][0],x+dx[ntype][0],ntype);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
        cin>>board[i][j];
    memset(dp,-1,sizeof(dp));
    cout<<dfs(0,1,1);
}