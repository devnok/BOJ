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

string d;
int n,dp[510][510],st[510];
int koi(char a,char b){return (a=='a'&&b=='t')||(a=='g'&&b=='c'); }
int solve(int s,int e){
  if(s>=e) return 0;
  int& ret = dp[s][e];
  if(~ret) return ret;
  // ret=max(solve(s+1,e), solve(s,e-1));
  if(koi(d[s],d[e])){
    ret = solve(s+1, e-1) + 2;
  }
  for(int i=s;i<e;i++) ret = max(ret, solve(s,i)+solve(i+1,e));
  return ret;
}
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  memset(dp,-1,sizeof(dp));
  cin>>d;
  n = sz(d);
  cout<<solve(0, n-1);
}