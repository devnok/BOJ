#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
const ll inf = 2e18;
const ll lim = 1e12;
struct Line{
    ll a,b;
    Line():Line(0,inf){}
    Line(ll _a,ll _b):a(_a),b(_b){}
    ll f(ll x){return a*x+b;}
};
const int sz = 1<<20;
Line v[sz];
int c[sz][2],piv=1,q;
void update(Line l,int p,ll s,ll e){
    Line lo=l,hi=v[p];
    if(lo.f(s)>hi.f(s)) swap(lo,hi);
    v[p]=lo;
    if(lo.f(e)<=hi.f(e)) return;
    ll m=(s+e)/2;
    if(lo.f(m)<hi.f(m)){
        if(!c[p][1]) c[p][1]=++piv;
        update(hi,c[p][1],m+1,e);
    } else {
        v[p]=hi;
        if(!c[p][0]) c[p][0]=++piv;
        update(lo,c[p][0],s,m);
    }
}
void update(ll a,ll b){update(Line(a,b),1,-lim,lim);}
ll query(ll x,int p,ll s,ll e){
    ll m=(s+e)/2;
    if(!p) return inf;
    if(x>m) return min(v[p].f(x),query(x,c[p][1],m+1,e));
    return min(v[p].f(x),query(x,c[p][0],s,m));
}
ll query(ll x){return query(x,1,-lim,lim);}
const int MAXN = 100010;
ll d[MAXN],s[MAXN],p[MAXN],dp[MAXN];
int n;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    for(int i=2;i<=n;i++) cin>>d[i],d[i]+=d[i-1];
    for(int i=1;i<n;i++) cin>>p[i]>>s[i];
    for(int i=1;i<=n;i++){
        dp[i] = (i>1)*query(d[i])+p[i];
        update(s[i],dp[i]-s[i]*d[i]);
    }
    cout<<dp[n];
}