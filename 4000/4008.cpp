#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)

using ll = long long;
using pii = pair<int,int>;
const int MAXN = 1000100;
struct CHT{
    ll la[MAXN],lb[MAXN],sz,p;
    double cross(int x,int y){ return (double)(lb[y]-lb[x])/(la[x]-la[y]); }
    void insert(ll x,ll y){
        la[sz]=x;
        lb[sz]=y;
        while(sz>1&&cross(sz,sz-1)<cross(sz-1,sz-2)){
            la[sz-1]=la[sz];
            lb[sz-1]=lb[sz];
            sz--;
        }
        sz++;
    }
    ll query(ll x){
        while(p+1<sz&&cross(p,p+1)<=x) p++;
        printf("%lld (%lld %lld)\n",x,la[p],lb[p]);
        return la[p]*x+lb[p];
    }
} C;
ll a,b,c,s[MAXN],dp[MAXN],p[MAXN];
int n,i;
int main(){
    cin>>n;
    cin>>a>>b>>c;
    for(i=1;i<=n;i++){
        scanf("%lld",s+i);
        p[i]=p[i-1]+s[i];
    }
    C.insert(0,0);
    for(i=1;i<=n;i++){
        dp[i] = C.query(p[i])+a*p[i]*p[i]+b*p[i]+c;
        C.insert(-2*a*p[i],a*p[i]*p[i]-b*p[i]+dp[i]);
        cout<<dp[i]<<endl;
    }
    cout<<dp[n];
}