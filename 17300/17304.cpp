#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int MAXN = 200020;
int N,M,safe[MAXN],v[MAXN],v2[MAXN];
set<int> adj[MAXN];
vector<int> g[MAXN];
int dfs(int x){
    v2[x]=1;
    int ret = safe[x];
    for(int i:g[x]){
        if(!v2[i]) ret+=dfs(i);
    }
    return ret;
}
int isNotTree(int x,int p){
    v[x]=v[p]+1;
    int ret = 0;
    for(int i:g[x]){
        if(p==i) continue;
        if(!v[i]) ret|=isNotTree(i,x);
        else if(v[x]>v[i]) return 1;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>N>>M;
    for(int a,b,i=0;i<M;i++){
        cin>>a>>b;
        if(adj[b].find(a)!=adj[b].end()){
            g[a].push_back(b);
            g[b].push_back(a);
            adj[b].erase(a);
        }
        else adj[a].insert(b);
    }
    for(int i=1;i<=N;i++) for(int j:adj[i]) safe[j]=1;
    for(int i=1;i<=N;i++){
        if(v2[i]) continue;
        if(!dfs(i)){
            if(!isNotTree(i,0)){
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
}