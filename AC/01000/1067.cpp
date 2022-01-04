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

#include<complex>
using base = complex<double>;
using vb = vector<base>;

void fft(vb& a, bool inv=false){
  int n = sz(a);
  for(int i=1,j=0;i<n;i++){
    int bit = n>>1;
    while(!((j^=bit) & bit)) bit>>=1;
    if(i<j) swap(a[i],a[j]);
  }
  for(int i=1;i<n;i<<=1){
    double x = M_PI / i * (inv ? -1 : 1);
    base w = {cos(x), sin(x)};
    for(int j=0;j<n;j+=i*2){
      base z = {1,0};
      for(int k=0;k<i;k++){
        base u=a[j+k], v=z*a[i+j+k];
        a[j+k] = u+v;
        a[i+j+k] = u-v;
        z *= w;
      }
    }
  }
  if(inv) for(auto& i:a) i/=n;
}
template<typename T>
vector<T> multiply(vector<T>& a,vector<T>& b){
  vb fa(all(a)), fb(all(b));
  int n=1, m=(a.size() + b.size() - 1);
  while(n<m) n<<=1;
  fa.resize(n); fb.resize(n);
  fft(fa); fft(fb);
  for(int i=0;i<n;i++) fa[i]*=fb[i];
  fft(fa, true);
  vector<T> ret(m);
  for(int i=0;i<m;i++) ret[i] = static_cast<T>(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
  return ret;
}

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n);
  vint a(n),b(n);
  for(int& i:a) cin>>i;
  for(int& i:b) cin>>i;
  a.insert(a.end(), all(a));
  reverse(all(b));
  vint c = multiply(a, b);
  int r=0;
  for(int i:c) r=max(r, i);
  cout<<r;
}