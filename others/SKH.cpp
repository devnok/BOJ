#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int apt[25][25];
int dange[625],v[625];
int dangeSu,n;
vector<int> adj[625];
void dfs(int x){
    v[x]=1;
    dange[dangeSu]++; 
    apt[x/n][x%n]=0;
    for(int i:adj[x]) if(!v[i]) dfs(i);  
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%1d",&apt[i][j]);
    for(int i=0;i<n*n;i++)
        if(apt[i/n][i%n]==1){
            if(i/n+1<n&&apt[i/n+1][i%n]==1) {adj[i].push_back(i+n); adj[i+n].push_back(i);}
            if(i/n-1>=0&&apt[i/n-1][i%n]==1) {adj[i].push_back(i-n); adj[i-n].push_back(i);}
            if(i%n+1<n&&apt[i/n][i%n+1]==1) {adj[i].push_back(i+1); adj[i+1].push_back(i);}
            if(i%n-1>=0&&apt[i/n][i%n-1]==1) {adj[i].push_back(i-1); adj[i-1].push_back(i);}
        }
    for(int i=0;i<n*n;i++)
        if(apt[i/n][i%n]==1){
            dfs(i);
            dangeSu++;
        }
    cout<<dangeSu;
    sort(dange,dange+dangeSu);
    for (int i = 0; i < dangeSu; i++)
        cout<<'\n'<<dange[i];
}