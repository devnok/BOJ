#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int MAXN = 30030;
using ll = long long;
using pll = pair<ll,ll>;
struct star{
    ll x,y,dx,dy;
    star(){}
    star(ll _x,ll _y,ll _dx,ll _dy){
        x=_x,y=_y;
        dx=_dx,dy=_dy;
    }
    pll after(int t){
        return {x+dx*t,y+dy*t};
    }
};
pll operator-(const pll& a,const pll& b){
    return pll(a.X-b.X,a.Y-b.Y);
}
int N,T;
ll ccw(pll v,pll w){return v.X*w.Y-w.X*v.Y;}
ll ccw(pll a,pll b,pll c){
    return ccw(b-a,c-a);
}
ll dis(pll a,pll b){
    pll v=b-a;
    return v.X*v.X+v.Y*v.Y;
}
star s[MAXN];
ll decision(int t){
    ll ret=0;
    pll p[MAXN],st[MAXN];
    for(int i=0;i<N;i++)
        p[i] = s[i].after(t);
    swap(p[0],*min_element(p,p+N));
    sort(p+1,p+N,[&](pll a,pll b){
        ll t = ccw(p[0],a,b);
        if(t) return t>0;
        return dis(p[0],a) < dis(p[0],b);
    });
    int c=0;
    st[c++]=p[0],st[c++]=p[1];
    for(int i=2;i<N;i++){
        while(c>1&&ccw(st[c-2],st[c-1],p[i])<=0) c--;
        st[c++]=p[i];
    }
    int i,j=1,ni,nj;
    for(i=0;i<c;i++){
        ni = (i+1)%c;
        while(1){
            nj = (j+1)%c;
            ll t = ccw(st[ni]-st[i],st[nj]-st[j]);
            if(t>0) j=nj;
            else break;
        }
        ret = max(ret,dis(st[i],st[j]));
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>N>>T;
    for(int x,y,dx,dy,i=0;i<N;i++){
        cin>>x>>y>>dx>>dy;
        s[i] = star(x,y,dx,dy);
    }
    int s=0,e=T;
    for(int i=0;i<100;i++){
        int l = (s*2+e)/3;
        int r = (s+e*2+1)/3;
        ll dl = decision(l);
        ll dr = decision(r);
        (dl<=dr)?e=r:s=l+1;
    }
    cout<<s<<" "<<decision(s);
}