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

using ti = tuple<int,int,int>;
const int MAXN = 200020;
vector<int> adj[MAXN];
int sz[MAXN],v[MAXN];


int get_sz(int x,int p){
  sz[x]=1;
  for(int i:adj[x]) if(i^p && !v[i]) sz[x]+=get_sz(i,x);
  return sz[x];
}
int cent(int x,int p,int s){
  for(int i:adj[x]) if(i^p && !v[i] && sz[i]*2>s) return cent(i,x,s);
  return x;
}
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n);
  strs(s);
  s="$"+s;
  for(int i=1;i<n;i++){
    ints(u,v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  auto add = [](ti ucp,char ch){
    auto [u,c,p] = ucp;
    if(ch=='U') return make_tuple(u+1,c,p);
    return ch=='C' ? make_tuple(u,c+1,p) : make_tuple(u,c,p+1);
  };
  function<ll(int)> solve = [&](int x){
    int c = cent(x,0,get_sz(x,0));
    ll ans = 0;
    v[c] = 1;
    map<pii, int> m;
    m.insert({{0,0}, 1});
    ti t = {0,0,0};
    function<void(int,int,ti,int)> dfs = [&](int x,int par,ti ucp,int type){
      auto [u,c,p] = ucp;
      if(type==1) {
        pii key = {u-p, u+p-c};
        auto it = m.find(key);
        ans += (it==m.end()) ? 0 : it->second;
      }
      if(type==2) {
        pii key = {p-u, c-u-p};
        auto it = m.find(key);
        if(it==m.end()) it = (m.insert({key, 0})).x;
        (it->second)++;
      }
      for(int i:adj[x]) if(i^par && !v[i]) dfs(i, x, add(ucp, s[i]), type);
    };
    for(int i:adj[c]){
      if(v[i]) continue;
      auto t1 = add(t, s[c]);
      dfs(i, c, add(t1, s[i]), 1);
      dfs(i, c, add(t, s[i]), 2);
    }
    for(int i:adj[c]) if(!v[i]) ans += solve(i);
    return ans;
  };
  cout<<solve(1);
}