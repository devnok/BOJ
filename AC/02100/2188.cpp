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

vint adj[202];
int nf(int n, int m){
  int r=0;
  vint v(m+1), par(m+1, -1);
  function<int(int)> dfs = [&](int x){
    for(int i:adj[x]){
      if(v[i]) continue;
      v[i] = 1;
      if(par[i]<0 || dfs(par[i])){
        par[i] = x;
        v[i] = 1;
        return 1;
      }
    }
    return 0;
  };
  for(int i=1;i<=n;i++){
    fill(all(v), 0);
    r += dfs(i);
  }
  return r;
}
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,m);
  for(int i=1;i<=n;i++){
    ints(j);
    while(j--){
      ints(s);
      adj[i].push_back(s);
    }
  }
  cout<<nf(n, m);
}