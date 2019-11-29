#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n,dist[1010],lca[1010];
vector<int> par[1010];
void dfs(int x){
    for(int i=1;i<dist[x];i++){
        lca[x]=i;
        par[x+1].push_back(1);
        for(int j=1;j<dist[x]-i;j++) par[x+1].push_back(0);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    for(int i=1;i<n;i++) cin>>dist[i];
    dfs(1);
}