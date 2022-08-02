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

#define x first
#define y second
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  lls(n,m,k);
  vll v(n);
  for(ll& i:v) cin>>i;
  auto solve = [&](vll v, ll x){
    ll ret=0;
    for(int i=0;i<n;i++) v[i]+=x;
    vll p(n);
    partial_sum(all(v), p.begin());
    p.insert(p.begin(), 0);
    for(int i=0;i<n;i++){
      ll idx = lower_bound(all(p), p[i]+m) - p.begin();
      ret += n-idx+1;
    }
    return ret;
  };
  ll s=0,e=m+1;
  for(int i=0;i<100;i++){
    ll mid = (s+e)/2;
    if(solve(v, mid)>=k) e=mid;
    else s=mid+1;
  }
  cout<<s;
}