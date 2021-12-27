#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;i++)

using ll = long long;
using pii = pair<int,int>;
const int MAXN = 1501;
ll dp[MAXN][MAXN],n,a[MAXN][MAXN],ans;
const int sz = 1 << 11;
struct Seg{
    ll dat[sz*2];
    ll get(int x){int r=dat[x+=sz]; for(x/=2;x;x/=2) r+=dat[x]; return r;}
    void update(int s,int e,ll v){
        for(s+=sz,e+=sz;s<=e;s/=2,e/=2){
            if(s%2) dat[s++]+=v;
            if(e%2==0) dat[e--]+=v;
        }
    }
} S[MAXN];
int s[MAXN],e[MAXN];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    REP(i,1,n){
        REP(j,1,n){
            cin>>a[i][j];
            dp[i][j] = a[i][j]+max(dp[i-1][j],dp[i][j-1]);
            S[i].update(j,j,dp[i][j]);
            ans+=dp[i][j];
        }
    }
    cout<<ans<<"\n";
    REP(i,1,n){
        char c;
        int x,y;
        ll v;
        cin>>c>>x>>y;
        v = c=='U'?1:-1;
        int ns=y,ne=y;
        REP(j,x,n){
            while(ne<n&&max(S[j-1].get(ne+1),S[j].get(ne))+v == max(S[j-1].get(ne+1),S[j].get(ne)+v)) ne++;
            e[j]=ne;
            s[j]=n+1;
        }
        s[x]=y;
        REP(j,x+1,n){
            while(ns<=n&&max(S[j-1].get(ns),S[j].get(ns-1))==max(S[j-1].get(ns)+v,S[j].get(ns-1))) ns++;
            if(ns>e[j]) break;
            s[j]=ns;
        }
        REP(j,x,n){
            S[j].update(s[j],e[j],v);
            if(s[j]<=e[j])
                ans+=(e[j]-s[j]+1)*v;
        }
    cout<<ans<<"\n";
    }
}