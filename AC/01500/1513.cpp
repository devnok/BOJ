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

const int K = 1000007;
int x[55],y[55],dp[55][55][55][55],v[55][55];
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,m,c);
  for(int i=1;i<=c;i++){
    cin>>x[i]>>y[i];
    v[x[i]][y[i]] = i;
  }
  x[c+1]=n,y[c+1]=m;
  memset(dp,-1,sizeof(dp));
  function<int(int,int,int,int)> solve = [&](int x,int y,int c,int a){
    if(!x || !y) return 0;
    int& ret = dp[x][y][c][a];
    if(~ret) return ret;
    if(v[x][y]){
      if(a<v[x][y]) return 0;
      c--, a=v[x][y];
    }
    if(c<0) return ret=0;
    if(c==0 && x==1 && y==1) return ret=1;
    return ret = (solve(x-1,y,c,a) + solve(x,y-1,c,a)) % K;
  };
  for(int i=0;i<=c;i++) cout<<solve(n,m,i,c+1)<<' ';
}