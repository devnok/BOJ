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
int dat[sz*2];

void update(int x,int v){
  dat[x+=sz]+=v;
  for(x/=2;x;x/=2) dat[x]=dat[2*x]+dat[2*x+1];
}
int get(int s,int e){
  int r=0;
  for(s+=sz,e+=sz;s<=e;s/=2,e/=2){
    if(s%2) r+=dat[s++];
    if(e%2==0) r+=dat[e--];
  }
  return r;
}

int get(int x,int l,int r,int k){
  if(l==r) return l;
  int mid = (l+r)/2;
  if(k<=dat[2*x]) return get(2*x,l,mid,k);
  return get(2*x+1,mid+1,r,k-dat[2*x]);
}
int get(int k){return get(1,0,sz-1,k);}
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,k);
  for(int i=1;i<=n;i++) update(i, 1);
  cout<<'<';
  for(int i=n,j=k;i;i--){
    j = (j-1)%i + 1;
    int h = get(j--);
    cout<<h;
    update(h, -1);
    if(i>1) cout<<", ";
    j += k;
  }
  cout<<'>';
}