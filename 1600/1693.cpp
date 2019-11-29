#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

using ll = long long;
const int MAXN = 100010;
const int MAXC = 32-__builtin_clz(MAXN)+1;
const ll INF = 1ll<<62;
vector<int> adj[MAXN];
int n,ans,C;
ll dp[MAXN][MAXC];
ll dfs(int x,int p,int c){
    ll& ret=dp[x][c];
    if(~ret) return ret;
    ret=c;
    for(int ch:adj[x]){
        if(ch^p){
            ll ps=INF;
            for(int i=1;i<=C;i++) if(i!=c) ps = min(ps,dfs(ch,x,i));
            ret+=ps;
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>n;
    C = 32-__builtin_clz(n)+1;
    for(int a,b,i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj[0].push_back(1);
    cout<<dfs(0,-1,0);
}