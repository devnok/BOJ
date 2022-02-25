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
  vint dat, sf, pf, mx;
  int sz;
  void init(int n){
    sz=1; while(sz<n) sz*=2;
    dat.resize(2*sz,0);
    sf.resize(2*sz,0);
    pf.resize(2*sz,0);
    mx.resize(2*sz,0);
  }
  int max3(int a,int b,int c){return max(a,max(b,c));}
  void update(int x,int v){
    x+=sz;
    dat[x] = mx[x] = pf[x] = sf[x] = v;
    for(x/=2;x;x/=2){
      int l=2*x,r=2*x+1;
      dat[x] = dat[l]+dat[r];
      mx[x] = max3(mx[l],mx[r],sf[l]+pf[r]);
      pf[x] = max(pf[l],dat[l]+pf[r]);
      sf[x] = max(sf[r],sf[l]+dat[r]);
    }
  }
  int get(int s,int e){
    vint a,b;
    for(s+=sz,e+=sz;s<=e;s/=2,e/=2){
      if(s%2) a.push_back(s++);
      if(e%2==0) b.push_back(e--);
    }
    reverse(all(b));
    for(int x:b) a.push_back(x);
    int ret=-(1e9),t=0;
    for(int x:a){
      ret = max3(ret, mx[x], t+pf[x]);
      t = max3(sf[x], t+dat[x], 0);
      // writeln(s,e,ret,x,dat[x],mx[x],pf[x],sf[x]);
    }
    return ret;
  }
} S;

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n);
  S.init(n+1);
  for(int a,i=1;i<=n;i++){
    cin>>a;
    S.update(i, a);
  }
  ints(m);
  while(m--){
    ints(i,j);
    cout<<S.get(i,j)<<'\n';
  }
}