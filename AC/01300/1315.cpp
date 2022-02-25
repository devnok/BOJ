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

int s[55],t[55],p[55],dp[2020][2020],n;
int solve(int st,int nt){
  if(st>=1000 || nt>=1000) return n;
  int& ret = dp[st][nt];
  if(~ret) return ret;

  int points=0;
  ret=0;
  for(int i=0;i<n;i++){
    if(s[i]<=st || t[i]<=nt) points+=p[i], ret++;
  }
  points -= (st-1) + (nt-1);
  if(!points) return ret;
  for(int i=0;i<=points;i++) ret = max(ret, solve(st+i, nt+points-i));
  return ret;
}
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  cin>>n;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++) cin>>s[i]>>t[i]>>p[i];
  cout<<solve(1,1);
}