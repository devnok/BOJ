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

const int MAXN = 1e6 + 100;
int e[MAXN];
vll p;

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    e[0]=e[1]=1;
    for(ll i=2;i<MAXN;i++) {
        if(e[i]) continue;
        for(ll j=i*i;j<MAXN;j+=i) e[j]=1;
        p.push_back(i);
    }
    int pn = p.size();
    int c; cin>>c;

    if(c<8) {
        puts("-1");
        return 0;
    }
    
    vint ans = {2};
    if(c%2) ans.push_back(3), c-=5;
    else ans.push_back(2), c-=4;
    for(int i=0;i<p.size();i++) {
        if(!e[c-p[i]]) {
            ans.push_back(p[i]);
            ans.push_back(c-p[i]);
            break;
        }
    }
    sort(all(ans));
    for(int i:ans) cout<<i<<" ";
}