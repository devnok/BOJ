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

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n);
  vint v(n);
  for(int& i:v) cin>>i;
  if(n==1){
    cout<<1<<'\n'<<v[0];
    return 0;
  }
  vint ans = {v[0]};
  int a=0;
  vint lis(n, 0);
  for(int i=1;i<n;i++){
    auto it = lower_bound(all(ans), v[i]);
    lis[i] = it - ans.begin();
    if(it!=ans.end()) *it = v[i];
    else ans.push_back(v[i]);
    a = max(a, sz(ans));
  }
  cout<<a<<'\n';
  vint b;
  for(int i=n;i--;){
    if(lis[i] == a-1){
      b.push_back(v[i]);
      a--;
    }
  }
  for(auto it=b.rbegin();it!=b.rend();++it) cout<<*it<<' ';
}