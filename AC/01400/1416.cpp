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

const int K = 999'983;
ll dp[51][550];
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(k);
  strs(s);
  vint d;
  dp[0][0] = 1;
  for(auto c:s) d.push_back(c-'0');
  for(int i=1;i<=k;i++){
    for(int j=0;j<=450;j++){
      for(int k:d){
        if(j>=k) dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % K;
      }
    }
  }
  ll ans=0,t=0;
  for(int i=0;i<=450;i++) ans = (ans + 2LL * dp[k][i]*dp[k][i]) % K;
  for(int i=0;i<=450;i++) for(int j=0;j<=450;j++){
    ll p = (dp[k/2][i]*dp[(k+1)/2][j]) % K;
    p = p*p%K;
    t = (t+p)%K;
  }
  cout<<(ans-t+K)%K;
}