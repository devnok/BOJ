#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define mp make_pair
const int INF = 987654321;

using pii = pair<int,int>;
vector<int> adj[1010], ans;
vector<pii> tk[2][1010][1010];
int dp[2][1010][1010],N,K,sz[1010],e[1010][1010],tmp[2][1010];
pii tr[2][1010];

void upd(int& dpn,int v,pii& x,int st,int y){
    if(dpn <= v) return;
    dpn = v;
    x = mp(st,y);
}
int dfs(int x,int p){
    sz[x]=1;
    dp[0][x][0] = dp[1][x][1] = 0;
    for(int c:adj[x]){
        if(c == p) continue; 
        sz[x]+=dfs(c,x);
        for(int i=0;i<=sz[x];i++) tmp[0][i]=tmp[1][i]=INF,tr[0][i]=mp(0,INF),tr[1][i]=mp(0,INF);

        for(int i=sz[x]-sz[c];i>=0;i--){
            for(int j=sz[c];j>=0;j--){
                upd(tmp[0][i+j],dp[0][x][i]+dp[0][c][j]+e[x][c],tr[0][i+j],0,j);
                upd(tmp[0][i+j],dp[0][x][i]+dp[1][c][j],tr[0][i+j],1,j);
                upd(tmp[1][i+j],dp[1][x][i]+dp[0][c][j],tr[1][i+j],0,j);
                upd(tmp[1][i+j],dp[1][x][i]+dp[1][c][j]+e[x][c],tr[1][i+j],1,j);
            }
        }
        for(int i=0;i<=sz[x];i++){
            dp[0][x][i] = tmp[0][i];
            tk[0][x][i].push_back(tr[0][i]);
            dp[1][x][i] = tmp[1][i];
            tk[1][x][i].push_back(tr[1][i]);
        }
    }
    return sz[x];
}
void g(int x,int p,int st,int cnt){
    if(st==1) ans.push_back(x);
    if(!cnt) return;
    reverse(adj[x].begin(),adj[x].end());
    int of = 0,c,i;
    for(i=0;i<adj[x].size();i++){
        c=adj[x][i];
        if(c==p){of=1;continue;}
        pii XY = tk[st][x][cnt][tk[st][x][cnt].size()-1-i+of];
        g(c,x,XY.first,XY.second);
        cnt-=XY.second;
    }
}
int main(){
    cin>>N>>K;
    for(int i=0;i<=N;i++)
        for(int j=0;j<=1000;j++) dp[1][i][j] = dp[0][i][j] = INF;
    for(int i=1,a,b,w;i<N;i++){
        cin>>a>>b>>w;
        adj[a].push_back(b);
        adj[b].push_back(a);
        e[a][b] = e[b][a] = w;
    }
    dfs(1,0);
    int ans1 = min(dp[0][1][K],dp[1][1][K]);
    (ans1 == dp[1][1][K]) ? g(1,0,1,K) : g(1,0,0,K);
    sort(ans.begin(),ans.end());
    cout<<ans1<<endl;
    for(int num:ans) cout<<num<<" ";
}