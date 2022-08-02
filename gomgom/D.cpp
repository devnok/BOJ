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
  ints(n);
  vint v(n);
  vint p(7, 0);
  for(int& i:v){
    cin>>i;
    i %= 7;
    vint q(7, 0);
    q[i] = 1;
    for(int j=0;j<7;j++) if(p[j]) q[(j+i)%7]=1;
    for(int j=0;j<7;j++) p[j] = p[j]|q[j];
  }
  puts(p[4] ? "YES" : "NO");
}