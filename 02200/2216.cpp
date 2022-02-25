#include <bits/stdc++.h>
using namespace std;

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

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int dp[3030][3030];
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(a,b,c);
  strs(x,y);
  auto max3 = [](int a,int b,int c){return max(a,max(b,c));};
  const int INF = 987654321;
  int xn = sz(x), yn = sz(y);
  for(int i=0;i<3000;i++) for(int j=0;j<3000;j++) dp[i][j]=-INF;
  function<int(int,int)> solve = [&](int n,int m){
    if(n==xn) return (yn-m)*b;
    if(m==yn) return (xn-n)*b;
    int& ret = dp[n][m];
    if(ret > -INF) return ret;
    ret = max3(solve(n+1,m)+b,solve(n,m+1)+b,solve(n+1,m+1)+(x[n]==y[m]?a:c));
    return ret;
  };
  cout<<solve(0,0);
}