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
    int dx,dy,i,j;

    bool operator < (const Line& rhs) const {
        ll l = (ll)dy*rhs.dx, r = (ll)dx*rhs.dy;
        return tie(l,i,j) < tie(r,rhs.i,rhs.j);
    }
    bool operator == (const Line& rhs) const{
        ll l = (ll)dy*rhs.dx, r = (ll)dx*rhs.dy;
        return l==r;
    }
};

pii operator - (const pii& l, const pii& r) { return {l.x-r.x, l.y-r.y}; }

ll ccw(pii a, pii b) {
    return (ll)a.x*b.y - (ll)a.y*b.x;
}

ll area(pii a, pii b, pii c) {
    ll k = ccw(b-a, c-b);
    return abs(k);
}

bool isIntersect(pii a, pii b, pii c, pii d) { // a-b & c-d
    ll l = ccw(c-d, d-a), r = ccw(c-d, d-b);
    return (l<0) != (r<0);
}

int main(void){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    vpii p(n);
    vint pos(n); iota(all(pos), 0);
    for(auto& [x,y]:p) cin>>x>>y;
    sort(all(p));

    vector<Line> lines;

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            lines.push_back({
                p[j].x-p[i].x,
                p[j].y-p[i].y,
                i,j
            });
        }
    }

    sort(all(lines));

    ll ans=0;

    ll m=9e18, mcnt=0;

    for(int i=0;i<lines.size();i++) {
        int a = lines[i].i, b = lines[i].j;
        swap(pos[a], pos[b]);
        swap(p[pos[a]], p[pos[b]]);

        a = pos[a], b = pos[b];

        if(a>b) swap(a,b);

        ans += (ll)a*(n-1-b);

        for(int l=max(0,a-3);l<a;l++) for(int r=b+1;r<min(n,b+4);r++) {
            ll ar = area(p[a],p[b],p[l]) + area(p[a],p[b],p[r]);
            if(ar == m) mcnt++;
            else if(ar < m) m=ar, mcnt=1;

            if(ar==m && !isIntersect(p[a],p[b],p[l],p[r])) mcnt++;
        }
    }
    cout<<(ans + mcnt);
}