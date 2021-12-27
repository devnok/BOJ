#include<bits/stdc++.h>
using namespace std;
#define W first
#define H second
using ll = long long;
const int MAXN = 100010;
ll i,n,a[MAXN],b[MAXN],dp[MAXN];
struct CHT{
    ll la[MAXN],lb[MAXN],sz,p;
    double cross(int x,int y){ return (double)(lb[y]-lb[x])/(la[x]-la[y]); }
    void insert(ll a,ll b){
        la[sz] = a,lb[sz] = b;
        while(cross(sz,sz-1)<cross(sz-1,sz-2)){
            la[sz-1] = la[sz];
            lb[sz-1] = lb[sz];
            sz--;
        }
        sz++;
    }
    ll query(ll x){
        while(p+1<sz&&cross(p,p+1)<=x) p++;
        return la[p]*x+lb[p];
    }
} C;
int main(){
    cin>>n;
    for(i=0;i<n;i++) scanf("%lld",a+i);
    for(i=0;i<n;i++) scanf("%lld",b+i);
    dp[0]=0;
    C.insert(b[0],0);
    for(i=1;i<n;i++){
        dp[i] = C.query(a[i]);
        C.insert(b[i],dp[i]);
    }
    cout<<dp[n-1];
}