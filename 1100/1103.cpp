#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)

const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int a[55][55];
int r,c,v[55][55],d[55][55],ans;
bool ok(int x,int y){
    return x>=0&&x<r&&y>=0&&y<c;
}
int dfs(int x,int y){
    if(!ok(x,y)||a[x][y]>9) return 0;
    if(v[x][y]){
        puts("-1");
        exit(0);
    }
    int& ret = d[x][y];
    if(~ret) return ret;
    v[x][y]=1;
    ret=0;
    for(int i=0;i<4;i++){
        int X = x+dx[i]*a[x][y];
        int Y = y+dy[i]*a[x][y];
        ret = max(ret,dfs(X,Y)+1);
    }
    ans = max(ans,ret);
    v[x][y]=0;
    return ret;
}
int main(){
    memset(d,-1,sizeof(d));
    cin>>r>>c;
    string s;
    for(int i=0;i<r;i++){
        cin>>s;
        for(int j=0;j<c;j++){
            if(s[j]>='0'&&s[j]<='9')
                a[i][j] = s[j]-'0';
            else a[i][j]=100;
        }
    }
    dfs(0,0);
    cout<<ans;
}