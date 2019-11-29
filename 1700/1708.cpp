#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define X first
#define Y second
using ll = long long;
using pll = pair<ll,ll>;
const int MAXN = 100010;
int N,c;
pll p[MAXN],st[MAXN];
pll operator-(const pll& a,const pll& b){
    return make_pair(a.X-b.X,a.Y-b.Y);
}
ll ccw(const pll& u,const pll& v){ return u.X*v.Y-v.X*u.Y; }
ll ccw(const pll& a,const pll& b,const pll& c){ // a-b a-c
    return ccw(b-a,c-a);
}
ll dis(const pll& a,const pll& b){
    pll u = b-a;
    return u.X*u.X+u.Y*u.Y;
}
ll mdis(){
    ll ret=0;
    int i,j=1,ni,nj;
    for(i=0;i<c;i++){
        ni = (i+1)%c;
        nj = (j+1)%c;
        ret = max(ret, dis(st[i],st[j]));
        while(ccw(st[ni]-st[i],st[nj]-st[j])>0){
            j=nj; nj=(j+1)%c;
            ret = max(ret, dis(st[i],st[j]));
        }
    }
    return ret;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)
        scanf("%lld %lld",&p[i].X,&p[i].Y);
    swap(p[0],*min_element(p,p+N));
    sort(p+1,p+N,[&](const pll& a,const pll&b){
        ll t = ccw(p[0],a,b);
        if(t) return t>0;
        return dis(p[0],a) < dis(p[0],b);
    });
    st[c++]=p[0];st[c++]=p[1];
    for(int i=2;i<N;i++){
        while(c>1&&ccw(st[c-2],st[c-1],p[i])<=0) c--;
        st[c++]=p[i];
    }
    printf("%.6lf",double(sqrt(mdis())));
}