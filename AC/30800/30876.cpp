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
#define vpiis(v, n) vpii v(n); for(auto& [i,j]:v) cin>>i>>j;
#define vlls(v, n) vll v(n); for(ll& i:v) cin>>i;

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vpiis(v, n);
    sort(all(v), [&](pii x, pii y){ return x.y < y.y; });
    cout<<v[0].x<<" "<<v[0].y;
}