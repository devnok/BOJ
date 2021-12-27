#include<bits/stdc++.h>
using namespace std;

vector<int> adj[31];
int n,s;
unordered_map<int,int> m[31];
const int CODE = 409;
const int CODE2 = 433;
int dfs(int x,int p){
    vector<int> v;
    for(int c:adj[x]){
        if(c==p) continue;
        v.push_back((CODE*dfs(c,x))^CODE);
    }
    if(v.empty()) return CODE/2;
    sort(v.begin(),v.end());
    int ret=0;
    for(int c:v){
        ret*=CODE2;
        ret+=c;
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    int ans=n,i,j,u,v;
    for(i=0;i<n;i++){
        scanf("%d",&s);
        for(j=0;j<s;j++) adj[j].clear();
        for(u,v,j=1;j<s;j++){
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int h,ok=1,mc=0;
        for(j=0;j<s;j++) mc = max(mc,int(adj[j].size()));
        for(j=0;j<s;j++){
            if(adj[j].size()!=mc) continue;
            h = dfs(j,-1);
            if(m[s].find(h) != m[s].end()){
                ans--; ok=0; break;
            }
        }
        if(ok) m[s][h]=i;
    }
    printf("%d",ans);
}