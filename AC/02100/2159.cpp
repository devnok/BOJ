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

const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
ll dp[100010][5];
ll dist(pll a,pll b){return abs(a.x-b.x)+abs(a.y-b.y);}
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n);
  vpll v(n);
  pll h;
  cin>>h.x>>h.y;
  const ll INF = 1LL<<62;
  auto inMap = [](int x,int y){
    return x>=0&&x<=100000&&y>=0&&y<=100000;
  };
  for(auto& [x,y]:v) cin>>x>>y;
  for(int i=0;i<4;i++){
      ll ax=v[0].x+dx[i], ay=v[0].y+dy[i];
      pll a = {ax,ay};
      dp[0][i] = dist(h, a);
  }
  for(int i=1;i<n;i++){
    for(int j=0;j<4;j++){
      ll ax=v[i].x+dx[j], ay=v[i].y+dy[j];
      pll a = {ax,ay};
      if(!inMap(ax,ay)) continue;
      dp[i][j] = INF;
      for(int k=0;k<4;k++){
        ll bx=v[i-1].x+dx[k], by=v[i-1].y+dy[k];
        pll b = {bx,by};
        if(!inMap(bx,by)) continue;
        dp[i][j] = min(dp[i][j], dp[i-1][k] + dist(a,b));
      }
    }
  }
  cout<<*min_element(dp[n-1], dp[n-1]+4);
}