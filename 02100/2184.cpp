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

int dp[1010][1010][2];

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,l);
  vint v(n);
  for(int& i:v) cin>>i;
  sort(all(v));
  memset(dp,-1,sizeof(dp));
  auto dis = [&](int i,int j){ return abs(v[i]-v[j]); };
  function<int(int,int,int)> solve = [&](int l,int r,int h){
    int& ret = dp[l][r][h];
    if(~ret) return ret;
    if(l==r) return ret = abs(l-v[l]);
    int len = (r-l+1);
    if(!h){
      return ret = min(
        solve(l+1, r, 0) + dis(l, l+1),
        solve(l+1, r, 1) + dis(l, r)
      );
    }
    return ret = min(
      solve(l, r-1, 0) + dis(l, r),
      solve(l, r-1, 1) + dis(r-1, r)
    );
  };
  cout << min(solve(0, n-1, 0),solve(0, n-1, 1));
}