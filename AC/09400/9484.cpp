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

struct Line {
    ll dx,dy,s,e;

    Line(ll _dx, ll _dy, ll _s, ll _e):dx(_dx),dy(_dy),s(_s),e(_e) {}

    bool operator < (const Line& rhs) const {
        ll l = dy*rhs.dx, r = dx*rhs.dy;
        if(l==r) return pii(s,e) < pii(rhs.s,rhs.e);
        return l<r;
    }

    bool operator == (const Line& rhs) const {
        ll l = dy*rhs.dx, r = dx*rhs.dy;
        return l == r;
    }
};

ll area(pii a, pii b, pii c) {
    ll k = ll(b.x-a.x)*(c.y-a.y)-ll(b.y-a.y)*(c.x-a.x);
    return abs(k);
}

int main(void){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while(1) {
        int n; cin>>n;
        if(!n) return 0;

        vpii p(n);
        vint pos(n);
        vector<Line> lines;
        for(auto& [x,y]:p) cin>>x>>y;

        sort(all(p));
        for(int i=0;i<n;i++) pos[i]=i;

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                lines.emplace_back(p[j].x-p[i].x,p[j].y-p[i].y,i,j);
            }
        }
        sort(all(lines));

        ll m = 987654321987654321;
        ll M = -1;

        int s = lines.size();

        for(int i=0;i<s;i++) {
            int a = lines[i].s, b = lines[i].e;

            swap(p[pos[a]], p[pos[b]]);
            swap(pos[a], pos[b]);

            if(pos[a]>pos[b]) swap(a,b);

            if(pos[a]>0) {
                m = min(m, area(p[pos[a]-1], p[pos[a]], p[pos[b]]));
                M = max(M, area(p[0], p[pos[a]], p[pos[b]]));
            }
            if(pos[b]+1<n) {
                m = min(m, area(p[pos[a]], p[pos[b]], p[pos[b]+1]));
                M = max(M, area(p[pos[a]], p[pos[b]], p[n-1]));
            }
        }
        printf("%lld.%lld %lld.%lld\n", m/2,m%2*5, M/2,M%2*5);
    }
}