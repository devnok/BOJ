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

using tiii = tuple<int,int,int>;

struct Line {
    int dx,dy,i,j,right;

    Line(int _dx, int _dy, int _i, int _j, int isRight = 0):i(_i), j(_j), right(isRight) {
        if(isRight) {
            if(_dy>=0) dx = _dy, dy = -_dx;
            else dx = -_dy, dy = _dx;
        }
        else dx=_dx, dy=_dy;
    }

    bool operator < (const Line& rhs) const {
        ll l = (ll)dy * rhs.dx, r = (ll)dx * rhs.dy;
        if(l!=r) return l<r;
        return tiii(-right, i, j) < tiii(-rhs.right, rhs.i, rhs.j);
    }
    bool operator == (const Line& rhs) const {
        ll l = (ll)dy * rhs.dx, r = (ll)dx * rhs.dy;
        return l == r;
    }
};

ll area(pii a, pii b, pii c) {
    ll k = ll(b.x-a.x)*(c.y-a.y) - ll(b.y-a.y)*(c.x-a.x);
    return abs(k);
}

double dis(pii a, pii b) { // between point to point
    ll k = (ll)(b.x-a.x)*(b.x-a.x) + (ll)(b.y-a.y)*(b.y-a.y);
    return pow(k, 0.5);
}

double dis(pii a, pii b, pii c) { // between line(a-b) & point(c)
    return area(a,b,c) / dis(a,b);
}

int main(void){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    vpii p(n);
    vint pos(n); iota(all(pos), 0);
    for(auto& [x,y]: p) cin>>x>>y;
    sort(all(p));

    vector<Line> lines;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            lines.emplace_back(
                p[j].x-p[i].x,
                p[j].y-p[i].y,
                i,j
            );
            lines.emplace_back(
                p[j].x-p[i].x,
                p[j].y-p[i].y,
                i,j,1
            );
        }
    }
    sort(all(lines));

    double ans = 0;
    for(int i=0;i<lines.size();i++) {
        int a = lines[i].i, b = lines[i].j;
        if(lines[i].right) {
            if(abs(pos[a]-pos[b])==1) {
                ans = max(ans, dis(p[pos[a]],p[pos[b]]));
            }
        }
        else {
            swap(pos[a], pos[b]);
            swap(p[pos[a]], p[pos[b]]);

            if(pos[a]>pos[b]) swap(a,b);

            if(pos[a]) ans = max(ans, dis(p[pos[a]],p[pos[b]],p[pos[a]-1]));
            if(pos[b]+1<n) ans = max(ans, dis(p[pos[a]],p[pos[b]],p[pos[b]+1]));
        }
        // printf("%c %d(%d)-%d(%d): %.4lf\n",lines[i].right ? 'R' : 'S',a,pos[a],b,pos[b],ans);
    }
    printf("%.10lf", ans/2);
}