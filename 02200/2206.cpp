#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int n,m;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int a[1010][1010];
int v[1010][1010][2];
struct state{
    pii xy;
    int t,d;
};
bool inMap(int x,int y){
    return x>=0&&y>=0&&x<n&&y<m;
}
const int INF = 987654321;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&a[i][j]);
            v[i][j][0]=v[i][j][1]=INF;
        }
    }
    queue<state> q;
    q.push({{0,0},0,1});
    v[0][0][0]=1;
    int x,y,t,d;
    pii xy;
    while(!q.empty()){
        tie(x,y) = q.front().xy;
        t = q.front().t;
        d = q.front().d; q.pop();
        if(d>v[x][y][t]) continue;
        for(int i=0;i<4;i++){
            int X = x+dx[i];
            int Y = y+dy[i];
            if(inMap(X,Y)){
                if(a[X][Y]){
                    if(!t&&v[X][Y][!t]>d+1){
                        v[X][Y][!t] = d+1;
                        q.push({{X,Y},!t,d+1});
                    }
                } else if(v[X][Y][t]>d+1){
                        v[X][Y][t] = d+1;
                        q.push({{X,Y},t,d+1});
                }
            }
        }
    }
    int ans = min(v[n-1][m-1][0],v[n-1][m-1][1]);
    if(ans==INF) puts("-1");
    else cout<<ans;
}