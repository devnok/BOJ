#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

using vint = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

#define x first
#define y second
#define all(v) (v).begin(), (v).end()

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n,s; cin>>n>>s;
    vint v(n);
    for(int& i:v) cin>>i;
    vint p;
    int hn = n>>1, k=0;
    for(int i=1;i<(1<<hn);i++) {
        if(i&1) k+=v[0];
        else {
            int j=0;
            for(;j<hn;j++){
                if((i>>j)&1) break;
                k-=v[j];
            }
            k+=v[j];
        }
        p.push_back(k);
    }
    p.push_back(0);
    sort(all(p));
    ll ans=0;
    int bn = n-hn;
    k=0;
    for(int i=0;i<(1<<bn);i++) {
        if(i==0);
        else if(i&1) k+=v[hn];
        else {
            int j=0;
            for(;j<bn;j++){
                if((i>>j)&1) break;
                k-=v[hn+j];
            }
            k+=v[hn+j];
        }
        int a = lower_bound(all(p), s-k) - p.begin();
        int b = upper_bound(all(p), s-k) - p.begin();
        if(k+p[a]==s) ans+=b-a;
        // printf("%d %d\n",k,ans);
    }
    if(s==0) ans--;
    cout<<ans;
}