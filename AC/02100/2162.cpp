#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

#define x first
#define y second
#define all(v) (v).begin(), (v).end()
#define vints(v, n) vint v(n); for(int& i:v) cin>>i;
#define vlls(v, n) vll v(n); for(ll& i:v) cin>>i;

ll ccw(pll a, pll b, pll c) {
    pll u = {b.x - a.x, b.y - a.y};
    pll v = {c.x - b.x, c.y - b.y};
    ll t = u.x * v.y - u.y * v.x;
    return t>0 ? 1 : t<0 ? -1 : 0;
}

struct Line {
    pll u,v;

    int is_inter(Line& rhs) {
        ll a = ccw(u, v, rhs.u) * ccw(u, v, rhs.v);
        ll b = ccw(rhs.u, rhs.v, u) * ccw(rhs.u, rhs.v, v);

        if(a==0 && b==0) {
            if(u > v) swap(u, v);
            if(rhs.u > rhs.v) swap(rhs.u, rhs.v);

            return rhs.u <= v && u <= rhs.v;
        }
        return a<=0 && b<=0;
    }
};

const int MAXN = 3030;
int par[MAXN], rk[MAXN];

void init(int n) {
    for(int i=0;i<=n;i++) par[i]=i, rk[i]=1;
}
int find(int p) { return par[p] = par[p]==p ? p : find(par[p]); }
void uni(int p,int q){
    int pp = find(p);
    int pq = find(q);
    par[pp] = pq;
    rk[pq] += rk[pp];
}

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<Line> l(n);
    for(auto& [u,v]:l) cin>>u.x>>u.y>>v.x>>v.y;

    init(n);
    int ans=n;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++) {
            if(l[i].is_inter(l[j])) {
                if(find(i) != find(j))
                    uni(i, j), ans--;
            }
        }
    }
    int m=0;
    for(int i=0;i<n;i++) m = max(m, rk[find(i)]);
    cout<<ans<<"\n"<<m;
}