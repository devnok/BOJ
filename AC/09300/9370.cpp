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

vpii adj[2020];

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(t);
  while(t--){
    ints(n,m,t);
    ints(s,g,h);
    for(int i=1;i<=n;i++) adj[i].clear();
    while(m--){
      ints(a,b,d);
      d*=2;
      if((a==g && b==h) || (a==h && b==g)) d-=1;
      adj[a].push_back({b,d});
      adj[b].push_back({a,d});
    }
    const int INF = 987654321;
    vint v(n+1, 0), d(n+1, INF), ans;
    while(t--){
      ints(x);
      v[x]=1;
    }
    priority_queue<tuple<int,int>> pq;
    pq.push({0, s});
    while(!pq.empty()){
      auto [w,x] = pq.top(); w=-w;
      pq.pop();
      if(w > d[x]) continue;
      if(v[x] && d[x]%2) ans.push_back(x);
      for(auto [i,j]: adj[x]){
        if(d[i] > w+j){
          d[i] = w+j;
          pq.push({-d[i], i});
        }
      }
    }
    sort(all(ans));
    for(int i:ans) cout<<i<<' ';
    cout<<'\n';
  }
}