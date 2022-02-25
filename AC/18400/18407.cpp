#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <bitset>
#include <functional>
#include <chrono>
#include <random>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
using namespace std;

using base = complex<double>;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;
using vb = vector<base>;

#define x first
#define y second
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define cpr(v) sort(all(v)); (v).erase(unique(all(v)), (v).end())
#define idx(v, x) int(lower_bound(all(v), (x)) - (v).begin())
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

struct Seg{
  vll dat, z;
  ll sz;
  void init(ll n){
    sz=1; while(sz<n) sz*=2;
    dat.resize(2*sz,0);
    z.resize(2*sz,0);
  }
  void q(ll& i,ll v){ if(i<v) i=v; }
  void push(ll x){
    q(dat[x], z[x]);
    if(x<sz){
      q(z[2*x], z[x]);
      q(z[2*x+1], z[x]);
    }
    z[x]=0;
  }
  void update(ll x,ll l,ll r,ll s,ll e,ll v){
    push(x);
    if(r<s||l>e) return;
    if(s<=l && r<=e){
      z[x]=v;
      push(x);
      return;
    }
    ll mid = (l+r)/2;
    update(2*x,l,mid,s,e,v);
    update(2*x+1,mid+1,r,s,e,v);
    dat[x] = max(dat[2*x],dat[2*x+1]);
  }
  void update(ll s,ll e,ll v){update(1,0,sz-1,s,e,v);}
  ll get(ll x,ll l,ll r,ll s,ll e){
    push(x);
    if(r<s||l>e) return 0;
    if(s<=l && r<=e) return dat[x];
    ll mid = (l+r)/2;
    return max(
      get(2*x,l,mid,s,e),
      get(2*x+1,mid+1,r,s,e)
    );
  }
  ll get(ll s,ll e){ return get(1,0,sz-1,s,e); }
} S;
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n);
  vll w(n),d(n),x;
  for(int i=0;i<n;i++){
    cin>>w[i]>>d[i];
    x.push_back(2*d[i]+1);
    x.push_back(2*(d[i]+w[i]));
  }
  cpr(x);
  S.init(sz(x));
  for(int i=0;i<n;i++){
    ll l=2*d[i]+1,r=d[i]+w[i];
    l = idx(x, l);
    r = idx(x, 2*r);
    // writeln(l,r,S.get(l,r),S.dat[1]);
    S.update(l,r,S.get(l,r)+1);
  }
  cout<<S.dat[1];
}