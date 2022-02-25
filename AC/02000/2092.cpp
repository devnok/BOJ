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

const int K = 1000000;
int cnt[202];
ll dp[202][4004] = {1};
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(t,a,s,b);
  for(int n,i=0;i<a;i++) cin>>n,cnt[n]++;
  ll ans=0;
  for(int i=1;i<=t;i++){
    dp[i][0]=1;
    for(int j=1;j<=b;j++){
      for(int k=0;k<=min(j,cnt[i]);k++) dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % K;
    }
  }
  for(int i=s;i<=b;i++) ans = (ans + dp[t][i]) % K;
  cout<<ans;
}