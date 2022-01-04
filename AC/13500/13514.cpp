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
using namespace std;

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

#define x first
#define y second
#define all(v) (v).begin(), (v).end()
#define cpr(v) sort(all(v)); (v).erase(unique(all(v)), (v).end())
#define idx(v, x) int(lower_bound(all(v), (x)) - (v).begin())
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

const int MAXN = 100010;
vint adj[MAXN], ct[MAXN];
int sz[MAXN], v[MAXN], c[MAXN], cpar[MAXN], cr, d[MAXN], par[MAXN][20];
multiset<int> s[MAXN];

int get_sz(int x,int p){
  sz[x] = 1;
  for(int i:adj[x]) if(!v[i] && i^p) sz[x] += get_sz(i,x);
  return sz[x];
}
void dfs(int x,int p){
  par[x][0] = p;
  d[x] = d[p] + 1;
  for(int i:adj[x]) if(i^p) dfs(i,x);
}
int cent(int x,int p,int s){
  for(int i:adj[x]) if(!v[i] && i^p && sz[i]*2>s) return cent(i,x,s);
  return x;
}
void make_ct(int x,int p){
  int c = cent(x,0,get_sz(x,0));
  v[c] = 1;
  cpar[c] = p;
  for(int i:adj[c]) if(!v[i]) make_ct(i, c);
}
int lca(int p,int q){
  if(d[p]<d[q]) swap(p,q);
  int diff = d[p]-d[q];
  for(int i=0;diff;i++){
    if(diff & 1) p = par[p][i];
    diff >>= 1;
  }
  if(p==q) return p;
  for(int i=19;~i;i--) if(par[p][i]^par[q][i]) p=par[p][i], q=par[q][i];
  return par[p][0];
}
int dist(int p,int q){
  return d[p]+d[q]-2*d[lca(p,q)];
}
void update(int x){
  c[x] = !c[x];
  int i = x;
  while(i){
    int d = dist(i,x);
    if(c[x]) s[i].insert(d);
    else s[i].erase(s[i].find(d));
    i = cpar[i];
  }
}
int query(int x){
  const int INF = 987654321;
  int r = INF;
  int i = x;
  while(i){
    int d = dist(i, x);
    if(!s[i].empty()) r = min(r, d + *s[i].begin());
    i = cpar[i];
  }
  return r==INF ? -1 : r;
}
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n);
  for(int i=1;i<n;i++){
    ints(a,b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1,0);
  for(int i=1;i<20;i++){
    for(int j=1;j<=n;j++){
      par[j][i] = par[par[j][i-1]][i-1];
    }
  }
  make_ct(1, 0);
  ints(m);
  while(m--){
    ints(a,b);
    if(a==1){
      update(b);
    }
    if(a==2){
      cout<<query(b)<<'\n';
    }
  }
}