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

int dp[10010][151],t[10010];
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,m);
  for(int a,i=0;i<m;i++) cin>>a,t[a]=1;
  memset(dp,-1,sizeof(dp));
  auto min3 = [](int a,int b,int c){return min(a,min(b,c));};
  const int INF = 987654321;
  function<int(int,int)> solve = [&](int x,int y){
    if(t[x]) return INF;
    if(y==0) return INF;
    if(x>=n) return x==n ? 0 : INF;
    int& ret = dp[x][y];
    if(~ret) return ret;
    return ret = min3(solve(x+y-1,y-1),solve(x+y,y),solve(x+y+1,y+1)) + 1;
  };
  int ans = solve(2,1)+1;
  cout<<(ans>=INF ? -1 : ans);
}