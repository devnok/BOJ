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

const int sz = 1<<17;
struct Seg{
  int dat[sz*2];
  void update(int s,int e,int v){
    for(s+=sz,e+=sz;s<=e;s/=2,e/=2){
      if(s%2) dat[s++]+=v;
      if(e%2==0) dat[e--]+=v;
    }
  }
  int get(int x){int r=0;for(x+=sz;x;x/=2) r+=dat[x]; return r;}
} S;

int f[100010];
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n);
  for(int i=0;i<n;i++){
    ints(l,r);
    cout<<S.get(l)-f[l]+S.get(r)-f[r]<<'\n';
    f[l]=S.get(l);
    f[r]=S.get(r);
    S.update(l+1,r-1,1);
  }
}