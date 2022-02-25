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
  lls(n);
  vll a(n);
  for(ll& i:a) cin>>i;
  sort(all(a));
  ll d=a[1]-a[0];
  if(d<1){
    cout<<"NO";
    return 0;
  }
  multiset<ll> m1(all(a));
  ll k;
  for(ll i=a[1];;i+=d){
    auto it = m1.find(i);
    if(it == m1.end()) break;
    m1.erase(it);
    k=i;
  }
  auto m2(m1);
  m2.insert(k);
  auto chk = [](multiset<ll> m){
    if(m.size()<2) return 0;
    ll s = *m.begin();
    ll d = *(++m.begin()) - s;
    if(d<1) return 0;
    for(auto it=m.begin();it!=m.end();++it){
      if(s!=*it) return 0;
      s+=d;
    }
    return 1;
  };
  cout<<(chk(m1)||chk(m2) ? "YES" : "NO");
}