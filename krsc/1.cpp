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
  int n; cin>>n;
  vint a(n), b(n);
  for(int& i:a) cin>>i;
  for(int& i:b) cin>>i;
  vint c(all(a)),d(a.rbegin(),a.rend());
  vint e(all(b)),f(b.rbegin(),b.rend());
  auto chk = [&](vint& a, vint& b){
    int t=0;
    for(int i=0;i+1<n;i++){
      if(a[i]==b[i]) continue;
      t++;
      a[i+1]^=(a[i]^b[i]); 
      a[i]=b[i];
    }
    if(a[n-1]!=b[n-1]) return n+1;
    return t;
  };
  int ans = min(chk(c,e),chk(d,f));
  if(ans>=n) cout<<-1;
  else cout<<ans;
}