#include<iostream>
#include<limits>
#include<algorithm>
using namespace std;
  
typedef unsigned long long ll;
const ll INF=numeric_limits<ll>::max();
struct xy{
    ll x,y;
    xy(ll _x=0,ll _y=0):x(_x),y(_y){}
    bool operator<(const xy& rhs){
        if(x==rhs.x) return y<rhs.y;
        return x<rhs.x;
    }
    xy operator-(const xy& rhs){
        return xy(x-rhs.x,y-rhs.y);
    }
    xy operator+(const xy& rhs){
        return xy(x+rhs.x,y+rhs.y);
    }
    xy operator*(const ll& t){
        return xy(x*t,y*t);
    }
} s1[30030], st[30030];
struct star{
    xy s,v;
    star(){}
    star(ll x,ll y,ll dx,ll dy):s({x,y}),v({dx,dy}){}
    xy after(ll t){ return s+v*t;}
} s[30030];
ll n,T;
ll ccw(xy u,xy v){ return (u.x*v.y-u.y*v.x); }
ll ccw(xy a,xy b,xy c){
    xy u=b-a,v=c-a;
    return ccw(u,v);
}
ll dis(xy a,xy b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
ll mdis(ll t){
    if(t<0 || t>T) return INF;
    for(ll i=0;i<n;i++)
        s1[i]=s[i].after(t);
    swap(s1[0],*min_element(s1,s1+n));
    sort(s1+1,s1+n,[&](const xy& a,const xy& b){
         return ccw(s1[0],a,b)>0;
    });
    ll top=0;
    st[top]=s1[0],st[++top]=s1[1];
    for(ll i=2;i<n;i++){
        while(top&&ccw(st[top-1],st[top],s1[i])<=0) top--;
        st[++top]=s1[i];
    }
    ll i,j=1,ni,nj=(j+1)%(top+1);
    ll ret=0;
    for(i=0;i<=top;i++){
        ni=(i+1)%(top+1);
        ret=max(ret,dis(st[i],st[j]));
        while(ccw(st[ni]-st[i],st[nj]-st[j])>0){
            j=nj; nj=(j+1)%(top+1);
            ret=max(ret,dis(st[i],st[j]));
        }
    }
    return ret;
}
int main(){
    cin>>n>>T;
    for(ll x,y,dx,dy,i=0;i<n;i++){
        scanf("%lld %lld %lld %lld",&x,&y,&dx,&dy);
        s[i]=star(x,y,dx,dy);
    }
    ll s=0,e=T;
    while(s<=e){
        ll l=(2*s+e)/3,r=(s+2*e+1)/3;
        if(mdis(l)<=mdis(r)) e=r-1;
        else s=l+1;
    }
    pair<ll,int> v[3];
    v[0] = make_pair(mdis(s-1),s-1);
    v[1] = make_pair(mdis(s),s);
    v[2] = make_pair(mdis(s+1),s+1);
    sort(v,v+3);
    cout<<v[0].second<<endl<<v[0].first;
}