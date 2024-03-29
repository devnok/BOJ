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
int v[1010];

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,l);
  for(int i=1;i<=n;i++) cin>>v[i];
  sort(v+1, v+n+1);
  function<int(int,int,int)> solve = [&](int l,int r,int h){
    if(l==1 && r==n) return 0;
    int& ret = dp[l][r][h];
    if(~ret) return ret;
    ret = 1e9;
    int here = h==0 ? l:r;
    if(l>1) ret = min(ret, solve(l-1,r,0) + (n-(r-l+1))*(v[here]-v[l-1]));
    if(r<n) ret = min(ret, solve(l,r+1,1) + (n-(r-l+1))*(v[r+1]-v[here]));
    return ret;
  };
  int x = lower_bound(v+1,v+n+1,l) - v;
  int ans = 1e9;
  if(x>1){
    memset(dp,-1,sizeof(dp));
    ans = min(ans, solve(x-1,x-1,0)+n*abs(l-v[x-1]));
  }
  if(x<=n){
    memset(dp,-1,sizeof(dp));
    ans = min(ans, solve(x,x,0)+n*abs(l-v[x]));
  }
  cout<<ans;
}