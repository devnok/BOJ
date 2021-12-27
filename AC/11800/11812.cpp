#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

typedef long long ll;
ll ks[101];
ll n,k,q,a,b;

ll h(ll x){
    for(int i=90;i>=0;i--)
        if(ks[i]<=x) return i+1;
    return 0;
}
ll par(ll x,ll h1){
    ll ret = (x-ks[h1-1])/k;
    return ret+(h1>1?ks[h1-2]:0);
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n>>k>>q;
    if(k==1){
        while(q--){
            cin>>a>>b;
            cout<<abs(a-b)<<"\n";
        }
        return 0;
    }
    fill(ks,ks+101,1LL<<52);
    ks[0]=1;
    for(ll i=1,p=k;p<(1LL<<50);i++,p*=k) ks[i]=p+ks[i-1];
    while(q--){
        cin>>a>>b;
        a--;b--;
        ll A=a,B=b,ans=0;
        if(h(a)<h(b)) swap(a,b);
        while(h(a)!=h(b)) ans++,a=par(a,h(a));
        while(a!=b){
            a=par(a,h(a));
            b=par(b,h(b));
            ans+=2;
        }
        cout<<ans<<"\n";
    }
}