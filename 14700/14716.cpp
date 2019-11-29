#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int dx[8]={0,0,-1,1,-1,-1,1,1};
const int dy[8]={-1,1,0,0,-1,1,-1,1};

int m,n,board[251][251],v[251][251],ans;

bool inRange(int x,int y){
    return x>=0&&x<m&&y>=0&&y<n;
}
void dfs(int x,int y){
    v[x][y]=1;
    for(int i=0;i<8;i++){
        int X=x+dx[i];
        int Y=y+dy[i];
        if(inRange(X,Y)&&!v[X][Y]&&board[X][Y]) dfs(X,Y);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!board[i][j]||v[i][j]) continue;
            dfs(i,j); ans++;
        }
    }
    cout<<ans;
}