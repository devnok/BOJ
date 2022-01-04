#include <iostream>
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

const int dx[8]={-1,-1,1,1,-1,0,1,0};
const int dy[8]={-1,1,-1,1,0,-1,0,1};
int c[505][505], b[505][505], l[505][505];
vint adj[505*505];

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,m,k);
  queue<pii> q;
  vpii v(k+1);
  for(int i=1;i<=k;i++){
    auto& [x,y] = v[i];
    cin>>x>>y;
    c[x][y]=i;
  }
  ints(s);
  q.push({s, 1});
  l[v[s].x][v[s].y] = 1;
  while(!q.empty()){
    auto [idx, level] = q.front(); q.pop();
    auto [x,y] = v[idx];
    adj[b[x][y]].push_back(idx);
    for(int i=0;i<8;i++){
      int X=x+dx[i], Y=y+dy[i];
      if(X<1||Y<1||X>n||Y>m) continue;
      if(!c[X][Y]) continue;
      if(!l[X][Y]){
        l[X][Y] = level+1;
        b[X][Y] = idx;
        q.push({c[X][Y], l[X][Y]});
      }
      if(l[X][Y] == level+1){
        b[X][Y] = min(b[X][Y], idx);
      }
    }
  }
  vint ans(k+1, 0);
  function<int(int)> dfs = [&](int x){
    ans[x] = 1;
    for(int i:adj[x]){
      ans[x] += dfs(i);
    }
    return ans[x];
  };
  dfs(s);
  if(ans[s] != k){
    cout<<-1;
    return 0;
  }
  for(int i=1;i<=k;i++) cout<<ans[i]<<' ';
}