#include <iostream>
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

int dp[101][100010];
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,m);
  vint s(n+1),p(n+1);
  auto max3 = [](int a,int b,int c){return max(a,max(b,c));};
  for(int i=1;i<=n;i++) cin>>s[i]>>p[i];
  const int INF = 987654321;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=m;j++){
      dp[i][j] = max3(
        j+p[i]>m ? -INF : dp[i-1][j+p[i]],
        j+p[i]+1>m ? -INF : dp[i-1][j+p[i]+1]+s[i],
        dp[i-1][j]-s[i]);
    }
  }
  if(dp[n][0] == 0) cout<<"D";
  if(dp[n][0] > 0) cout<<"W";
  if(dp[n][0] < 0) cout<<"L";
}