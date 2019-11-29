#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n,m,k,ans;
int v[51],adj[51][51],ctt[51],pt[51][51];
void dfs(int x){
    if(v[x]) return;
    ctt[x]=v[x]=1;
    for(int i=1;i<=n;i++) if(!v[i]&&adj[x][i]) dfs(i);
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n>>m>>k;
    vector<int> s(k);
    for(int i=0;i<k;i++)
        cin>>s[i];
    for(int i=0,c;i<m;i++){
        cin>>c;
        for(int j=0;j<c;j++){
            cin>>pt[i][j];
        }
        for(int j=0;j<c;j++){
            for(int k=0;k<c;k++){
                int u=pt[i][j],v=pt[i][k];
                if(j!=k) adj[u][v]=adj[v][u]=1;
            }
        }
    }
    for(int i=0;i<k;i++){
        dfs(s[i]);
    }
    for(int i=0;i<m;i++) if(!ctt[pt[i][0]]) ans++;
    cout<<ans;
}