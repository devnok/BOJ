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

string p;
int n,dp[202][202];
int equal(int a,int b,int l){
  if(a>b) swap(a,b);
  if(b+l>n) return 0;
  for(int i=0;i<l;i++) if(p[a+i]!=p[b+i]) return 0;
  return 1;
}
int sb(int num){
  if(num>99) return 3;
  if(num>9) return 2;
  return 1;
}
int solve(int s,int e){
  int l = e-s+1;
  if(l==1) return l;
  int& ret = dp[s][e];
  if(~ret) return ret;
  ret = l;
  for(int i=1;i<l;i++){
    if(l%i) continue;
    int j;
    for(j=s+i;j<=e;j+=i) if(!equal(s,j,i)) break;
    if(j<=e) continue;
    ret = min(ret, solve(s,s+i-1)+2+sb(l/i));
  }
  // if(ret!=l) writeln(s,e,p.substr(s,l),ret);
  for(int k=s;k<e;k++)
    ret = min(ret, solve(s,k)+solve(k+1,e));
  return ret;
}
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  cin>>p;
  n = sz(p);
  memset(dp,-1,sizeof(dp));
  cout<<solve(0,n-1);
}