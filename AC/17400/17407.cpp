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

string s;
struct Seg{
  int sz;
  vint dat,v,m;
  // v: 괄호가 유효한가
  // m: 최대로 닫힐때
  void init(int n){
    sz=1; while(sz<n) sz<<=1;
    dat.resize(2*sz);
    v.resize(2*sz);
    m.resize(2*sz,0);
    for(int i=0;i<n;i++){
      int x=i+sz;
      dat[x]=v[x]=1;
      for(x/=2;x;x/=2){
        dat[x]=dat[2*x]+dat[2*x+1];
        v[x]=1;
      }
    }
  }
  void update(int x){
    x+=sz;
    dat[x]=-dat[x];
    m[x]=dat[x];
    v[x]=dat[x];
    for(x/=2;x;x/=2){
      dat[x]=dat[2*x]+dat[2*x+1];
      v[x] = v[2*x];
      if(dat[2*x]+m[2*x+1]<0) v[x]=-1; // 괄호가 중간에 닫힘
      m[x] = min(0, min(m[2*x],dat[2*x]+m[2*x+1]));
    }
  }
  int valid(int s,int e){
    vint a,b;
    for(s+=sz,e+=sz;s<=e;s/=2,e/=2){
      if(s%2) a.push_back(s++);
      if(e%2==0) b.push_back(e--);
    }
    for(auto it=b.rbegin();it!=b.rend();++it) a.push_back(*it);
    int t=0;
    for(int x:a){
      if(t+m[x]<0) return 0;
      t+=dat[x];
    }
    return t==0;
  }
} S;
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  cin>>s;
  int n = sz(s);
  S.init(n);
  for(int i=0;i<n;i++) if(s[i]==')') S.update(i);
  ints(m);
  int ans=0;
  while(m--){
    // for(int i=1;i<=S.sz;i*=2){
    //   for(int j=0;j<i;j++){
    //     printf("(%d %d %d) ",S.dat[i+j],S.m[i+j],S.v[i+j]);
    //   }
    //   cout<<endl;
    // }
    ints(x);
    S.update(x-1);
    ans += S.valid(0,n-1);
  }
  cout<<ans;
}