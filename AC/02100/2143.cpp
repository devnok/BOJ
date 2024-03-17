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
#define vints(v, n) vint v(n); for(int& i:v) cin>>i;
#define vlls(v, n) vll v(n); for(ll& i:v) cin>>i;

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int t,an,bn;
    cin>>t;
    cin>>an;
    vints(a, an);
    cin>>bn;
    vints(b, bn);
    vll p;
    for(int i=0;i<an;i++){
        ll k=0;
        for(int j=i;j<an;j++) {
            k+=a[j];
            p.push_back(k);
        }
    }
    sort(all(p));
    ll ans=0;
    for(int i=0;i<bn;i++){
        ll k=0;
        for(int j=i;j<bn;j++) {
            k+=b[j];
            int s = lower_bound(all(p), t-k) - p.begin();
            int e = upper_bound(all(p), t-k) - p.begin();
            if(s<p.size() && k+p[s]==t) ans += e-s;
        }
    }
    cout<<ans;
}