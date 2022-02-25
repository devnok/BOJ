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

const int MAXN = 100010;
ll v[MAXN], t[MAXN], n, d;
ll D[MAXN], K[MAXN], ans;

void solve(int s,int e,int p,int q){
  if(s>e) return;
  int m = (s+e)/2;

  for(int k=p;k<=min(m,q);k++){
    if(abs(k-m)>d) continue;
    ll s=(m-k)*t[m]+v[k];
    if(D[m]<s) D[m]=s,K[m]=k;
  }
  ans = max(ans, D[m]);
  solve(s,m-1,p,K[m]);
  solve(m+1,e,K[m],q);
}
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>d;
  for(int i=0;i<n;i++) cin>>t[i];
  for(int i=0;i<n;i++) cin>>v[i];
  solve(0,n-1,0,n-1);
  cout<<ans;
}