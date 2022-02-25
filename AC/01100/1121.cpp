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

ll dp[50050][11],a[51];
const int D = 50001;
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n);
  ll ans=0;
  for(int i=1;i<=n;i++) cin>>a[i];
  ints(K);
  sort(a+1, a+n+1);
  dp[0][0] = 1;
  for(int i=1;i<=n;i++){
    for(int j=a[i]+1;j<=D;j++) ans += dp[j][K-1];
    for(int j=D;j>=D-a[i];j--){
      for(int k=K;k;k--){
        dp[D][k] += dp[j][k-1];
      }
    }
    for(int j=D-1;j>=a[i];j--){
      for(int k=K;k;k--){
        if(j>=a[i]) dp[j][k] += dp[j-a[i]][k-1];
      }
    }
  }
  cout<<ans;
}
