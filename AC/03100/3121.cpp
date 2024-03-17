#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;

using vint = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

#define x first
#define y second
#define all(v) (v).begin(), (v).end()
#define vints(v, n) vint v(n); for(int& i:v) cin>>i;
#define vlls(v, n) vll v(n); for(ll& i:v) cin>>i;

const int sz = 100010;

struct Seg{
    ll dat[sz*2],sf[sz*2],pf[sz*2],mx[sz*2];
    void init(){
        for(int i=0;i<sz*2;i++)
            dat[i]=sf[i]=pf[i]=mx[i]=0;
    }
    void update(int x,int w){
        dat[x+=sz]=w;
        mx[x]=max(0LL,dat[x]);
        pf[x]=sf[x]=mx[x];
        int sz = 1;
        for(x/=2;x;x/=2,sz*=2){
            pf[x]=max(pf[2*x], dat[2*x]?sz+pf[2*x+1]:0);
            sf[x]=max(sf[2*x+1],dat[2*x+1]?sz+sf[2*x]:0);
            mx[x]=max({mx[2*x],mx[2*x+1],sf[2*x]+pf[2*x+1]});
            dat[x]=dat[2*x] && dat[2*x+1];
        }
    }
} S;

struct Point {
    ll x,y,c;

    bool operator < (const Point& rhs) const {
        return pii(x, y) < pii(rhs.x, rhs.y);
    }
};

struct Line {
    ll dx,dy,i,j;

    bool operator < (const Line& rhs) const {
        ll l = dy*rhs.dx, r = dx*rhs.dy;
        if(l==r) return pii(i,j) < pii(rhs.i, rhs.j);
        return l<r;
    }

    bool operator == (const Line& rhs) const {
        ll l = dy*rhs.dx, r = dx*rhs.dy;
        return l == r;
    }
};

int main(void){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    vector<Point> v(n);
    vint pos(n);
    vector<Line> lines;

    for(int i=0;i<n;i++) {
        int x,y; char c;
        cin>>x>>y>>c;
        v[i] = {x, y, c == 'R' ? 1 : 0};
    }
    sort(all(v));
    for(int i=0;i<n;i++) pos[i] = i;

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int dx = v[j].x - v[i].x;
            int dy = v[j].y - v[i].y;
            lines.push_back({dx,dy,i,j});
        }
    }
    sort(all(lines));

    for(int i=0;i<n;i++) S.update(i, v[i].c);

    ll ans = S.mx[1];

    for(int i=0;i<lines.size();i++) {
        int a = lines[i].i, b = lines[i].j;
        swap(v[pos[a]], v[pos[b]]);
        swap(pos[a], pos[b]);
        S.update(pos[a], v[pos[a]].c);
        S.update(pos[b], v[pos[b]].c);
        
        if(i+1<lines.size() && lines[i+1] == lines[i]) continue;

        ans = max(S.mx[1], ans);
    }

    cout<<ans;
}