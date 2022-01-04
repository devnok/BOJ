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
int dp[101][10][10][10][2];
int n,a[110], b[110];
int mod(int x){
  return (x+10)%10;
}
int solve(int p,int x,int y,int z,int w){
  if(p==n) return 0;
  int& ret = dp[p][x][y][z][w];
  if(~ret) return ret;
  if(x==b[p]) return ret=min(solve(p+1,y,z,a[p+3],w),solve(p+1,y,z,a[p+3],!w));
  ret=1e9;
  for(int k=1;k<=3;k++){
    int d = w?k:-k;
    ret = min(ret, solve(p,mod(x+d),y,z,w)+1);
    ret = min(ret, solve(p,mod(x+d),mod(y+d),z,w)+1);
    ret = min(ret, solve(p,mod(x+d),mod(y+d),mod(z+d),w)+1);
  }
  return ret;
}
int main(void){
  cin>>n;
  for(int i=0;i<n;i++) scanf("%1d",&a[i]);
  for(int i=0;i<n;i++) scanf("%1d",&b[i]);
  memset(dp,-1,sizeof(dp));
  cout<<min(solve(0,a[0],a[1],a[2],0), solve(0,a[0],a[1],a[2],1));
}