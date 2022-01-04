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

const int MAXN = 404;
int dp[MAXN][MAXN][MAXN];
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n);
  vint a,b;
  for(int i=0;i<n;i++){
    ints(c);
    if(c) a.push_back(c);
  }
  for(int i=0;i<n;i++){
    ints(c);
    if(c) b.push_back(c);
  }
  const int INF = 987654321;
  int an = sz(a), bn = sz(b);
  for(int i=0;i<=n;i++)
    for(int j=0;j<=an;j++)
      for(int k=0;k<=bn;k++)
        dp[i][j][k] = -INF;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=min(i,an);j++) dp[i][j][0] = 0;
    for(int k=0;k<=min(i,bn);k++) dp[i][0][k] = 0;
  }
  auto max3 = [](int a,int b,int c){return max(max(a,b),c);};
  for(int i=1;i<=n;i++){
    for(int j=1;j<=min(i,an);j++){
      for(int k=1;k<=min(i,bn);k++){
        dp[i][j][k] =
          max3(
            dp[i-1][j][k-1],
            dp[i-1][j-1][k],
            dp[i-1][j-1][k-1] + a[j-1]*b[k-1]
          );
      }
    }
  }
  cout<<dp[n][an][bn];
}