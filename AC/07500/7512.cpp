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

const int MAXN = 1e7 + 100;
int e[MAXN];

struct A {
    ll prime;
    ll ni;
    ll st;
    A(ll _p, ll _i, ll _st):prime(_p), ni(_i), st(_st){}
    const bool operator < (const A& rhs) const { return rhs.prime < prime; }
};

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    vll p, ps;
    ps.push_back(0);
    for(ll i=2;i<MAXN;i++) {
        if(e[i]) continue;
        for(ll j=i*i;j<MAXN;j+=i) e[j]=1;
        p.push_back(i);
        ps.push_back(ps.back() + p.back());
    }
    int pn = p.size();
    int c; cin>>c;
    for(int s=1;s<=c;s++){
        int m; cin>>m;
        vint v(m);
        for(int& i:v) cin>>i;

        ll mprime = -1;

        priority_queue<A> pq;
        for(int i=0;i<m;i++) {
            for(int j=0;;j++) { // j ~ j+v[i]-1
                int p = ps[j+v[i]]-ps[j];
                if(e[p]) continue;
                pq.emplace(p, v[i], j);
                if(mprime < p) mprime = p;
                break;
            }
        }
        while(1) {
            A h = pq.top(); pq.pop();

            if(mprime == h.prime) break;

            for(int i=h.st+1;;i++) { // j ~ j+v[i]-1
                int p = ps[i+h.ni]-ps[i];
                if(e[p]) continue;
                pq.emplace(p, h.ni, i);
                if(mprime < p) mprime = p;
                break;
            }
        }

        printf("Scenario %d:\n%lld\n\n", s, mprime);
    }
}