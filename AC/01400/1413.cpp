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
int N,M;
ll dp[21][21];
ll solve(ll n,ll m){
  if(n==0) return 1;
  if(m==0) return 0;
  ll& ret = dp[n][m];
  if(~ret) return ret;
  ret = 0;
  ll t=1;
  for(int i=1;i<=n;i++){
    ret += t * solve(n-i, m-1);
    t*=(n-i);
  }
  return ret;
}

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  cin>>N>>M;
  memset(dp,-1,sizeof(dp));
  ll a=solve(N,M);
  ll b=solve(N,N);
  ll g = gcd(a,b);
  cout<<a/g<<'/'<<b/g;
}