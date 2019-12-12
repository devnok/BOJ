#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const ll inf = 2e18;
const ll lim = 1e12;
const ll sz = 1<<20;
ll get(pll l,ll x){return l.first*x+l.second;}
const pll L(0,-inf);
struct Node{
    pll se,l;
    Node(){}
    Node(pll _se,pll _l):se(_se),l(_l){}
} dat[sz];
int c[sz][2],piv,q;
void update(int p,pll l){
    ll s,e,m;
    tie(s,e) = dat[p].se;
    m = (s+e)/2;
    pll lo=dat[p].l,hi=l;
    if(get(lo,s)>get(hi,s)) swap(lo,hi);
    dat[p].l = hi;
    if(get(lo,e)<=get(hi,e)) return;
    if(get(lo,m)<get(hi,m)){
        if(!c[p][1]) dat[++piv]=Node({m+1,e},L),c[p][1]=piv;
        update(c[p][1],lo);
    } else {
        dat[p].l = lo;
        if(!c[p][0]) dat[++piv]=Node({s,m},L),c[p][0]=piv;
        update(c[p][0],hi);
    }
}
void insert(ll a,ll b){update(1,{a,b});}
ll query(int p,ll x){
    if(!p) return -inf;
    ll s,e;
    tie(s,e)=dat[p].se;
    ll m=(s+e)/2, ret=get(dat[p].l,x);
    return max(ret, query(c[p][x>m],x));
}
int main(){
    cin>>q;
    dat[++piv] = Node({-lim,lim},L);
    while(q--){
        ll a,b,c;
        scanf("%lld%lld",&c,&a);
        if(c==1) scanf("%lld",&b),insert(a,b);
        else printf("%lld\n",query(1,a));
    }
}