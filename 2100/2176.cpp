#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<functional>
#include<string.h>
using namespace std;
#define mp make_pair

typedef pair<int,int> pii;
const int MAXN=1010;
const int INF = 987654321;

int dist[MAXN][MAXN],n,m,ans,dp[MAXN];
vector<pii> adj[MAXN];

void dijkstra(int s){
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(mp(0,s));
    dist[s][s]=0;
    while(!pq.empty()){
        int here = pq.top().second, d = pq.top().first;
        pq.pop();
        if(dist[s][here] < d) continue;
        for(pii p : adj[here]){
            int next=p.first, w = p.second;
            if(dist[s][next] > dist[s][here] + w){
                dist[s][next] = dist[s][here] + w;
                pq.push(mp(dist[s][next],next));
            }
        }
    }
}
int reasonable_path(int x){
    //cout<<x<<endl;
    int& ret = dp[x];
    if(ret != -1) return ret;
    if(x==2) return ret=1;
    ret=0;
    for(pii i : adj[x]){
        int next = i.first;
        if(dist[x][2] > dist[next][2])
            ret += reasonable_path(next);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n>>m;
    for(int u,v,w,i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back(mp(v,w));
        adj[v].push_back(mp(u,w));
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dist[i][j]=INF;
        dijkstra(i);
    }
    memset(dp,-1,sizeof(dp));
    cout<<reasonable_path(1);
}