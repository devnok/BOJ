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

ll dp[52][52];
ll c[52][52] = {1};
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n);
  lls(k); k++;
  char ans[60];
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++){
    c[i][0] = 1;
    for(int j=1;j<=i;j++) c[i][j] = c[i-1][j-1] + c[i-1][j];
  }
  function<ll(int,int)> cnt = [&](int x,int y) -> ll{
    if(x<0) return 1LL<<y;
    if(y==0) return x!=0;
    ll& ret = dp[x][y];
    if(~ret) return ret;
    return ret = cnt(x+1, y-1) + cnt(x-1, y-1);
  };
  function<ll(int,ll)> solve2 = [&](int x,ll k){
    if(x==n){
      return k;
    }
    ll m = 1LL<<(n-x-1);
    if(m>=k){
      ans[x] = '(';
      return solve2(x+1, k);
    }
    ans[x]=')';
    return solve2(x+1, k-m);
  };
  function<ll(int,int,ll)> solve = [&](int x,int r,ll k){
    if(r<0) return solve2(x,k);
    if(x==n) return k;
    ll m = cnt(r+1, n-x-1);
    if(m>=k){
      ans[x] = '(';
      return solve(x+1, r+1, k);
    }
    ans[x]=')';
    return solve(x+1, r-1, k-m);
  };
  ll r = solve(0, 0, k);
  if(r!=1){
    cout<<-1;
    return 0;
  }
  ans[n]=0;
  cout<<ans;
}