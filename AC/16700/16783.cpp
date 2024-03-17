#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll, ll>;

#define x first
#define y second
#define all(v) (v).begin(), (v).end()

const int sz = 1<<11;
struct Seg {
    ll dat[sz*2], sf[sz*2], pf[sz*2], mx[sz*2];

    void update(int x, int v) {
        dat[x+=sz] = v;
        pf[x]=sf[x]=mx[x]=max(0, v);
        for(x/=2;x;x/=2) {
            pf[x] = max(pf[2*x], dat[2*x]+pf[2*x+1]);
            sf[x] = max(sf[2*x+1], dat[2*x+1]+sf[2*x]);
            mx[x] = max({mx[2*x],mx[2*x+1], sf[2*x]+pf[2*x+1]});
            dat[x] = dat[2*x]+dat[2*x+1];
        }
    }
    ll get() {
        return mx[1];
    }
} S;

struct Point {
    int x,y,v;

    bool operator < (const Point& rhs) const {
        return pii(x, y) < pii(rhs.x, rhs.y);
    }
};

struct Line {
    int dx,dy,i,j;

    bool operator < (const Line& rhs) const {
        ll l = (ll)dy*rhs.dx, r = (ll)dx*rhs.dy;
        return tie(l, i, j) < tie(r, rhs.i, rhs.j);
    }

    bool operator == (const Line& rhs) const { 
        return dy*rhs.dx == dx*rhs.dy;
    }
};

int main(void){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    vector<Point> p(n);
    for(auto& [x,y,v]:p) cin>>x>>y>>v;

    sort(all(p));
    vector<int> pos(n);

    vector<Line> lines;

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            lines.push_back({p[j].x-p[i].x,p[j].y-p[i].y,i,j});
        }
    }

    for(int i=0;i<n;i++) {
        S.update(i, p[i].v);
        pos[i]=i;
    }

    sort(all(lines));
    ll ans = S.get();

    for(int i=0;i<lines.size();i++) {
        int a = lines[i].i, b = lines[i].j;
        swap(pos[a], pos[b]);

        S.update(pos[a], p[a].v);
        S.update(pos[b], p[b].v);

        if(i+1<lines.size() && lines[i] == lines[i+1]) continue;

        ans = max(ans, S.get());
    }
    cout<<ans;
}