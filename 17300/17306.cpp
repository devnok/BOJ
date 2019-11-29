#include<iostream>
#include<vector>
#include<string>
using namespace std;

using ll = long long;
const ll test = 1ll << 50;
const int MAXN = 250025;
const int MAXV = MAXN*51;
ll ans,x;
int n,trie[MAXV][2],piv,dp[MAXV],k;
vector<ll> v;
int add(int p,ll x,int d){
    if(d<0) return dp[p]=1;
    int v = (x>>d)&1;
    if(!trie[p][v])
        trie[p][v] = ++piv;
    add(trie[p][v],x,d-1);
}
void dfs(int x){
    for(int c:trie[x])
        if(c) dfs(c),dp[x]+=dp[c];
    if(dp[x]&&dp[x]<n) ans++;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        for(k=0;x;x/=2,k++);
        add(0,i,k-2);
    }
    dfs(0);
    cout<<ans+1;
}