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
#define vints(v, n) vint v(n); for(int& i:v) cin>>i;
#define vlls(v, n) vll v(n); for(ll& i:v) cin>>i;

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

ll ps[100010], v[100010];

int main(void){
  lls(n,b,a);
  a=min(a,n);
  for(int i=1;i<=n;i++) cin>>v[i];
  sort(v, v+n+1);
  for(int i=1;i<=n;i++) ps[i]=ps[i-1]+v[i];
  int l = upper_bound(ps, ps+n+1, b) - ps;
  int r = l; // [l, r)
  ll c = b - ps[l-1];

  while(r-l < a) {
    if(l<0 || r>n) break;
    // printf("%lld %lld %lld\n", v[l], v[r], c);
    if(c >= v[r]>>1) c-=v[r++]>>1;
    else c+=v[--l]>>1;
  }
  cout<<r-1;
}