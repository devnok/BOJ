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
  int n, m=0; cin>>n;
  vint a(n);
  for(int& i:a) cin>>i, m+=i;
  int l=m/n, h=m/n+(m%n?1:0), b=0,c=0;
  for(int i:a){
    if(i<l) b+=l-i;
    if(i>h) c+=i-h;
  }
  cout<<max(b,c);
}