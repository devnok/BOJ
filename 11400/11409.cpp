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

pii nf(int n,int m){
  int r=0, cost=0;
  const int INF = 987654321;
  auto spfa = [&]{
    queue<int> q;
    vint inq(n,0);
    vint d(n, INF);
    vint p(n, -1);
    q.push(s);
    inq[s]=1;
    d[s]=0;
    while(!q.empty()){
      int t=q.front(); q.pop();
      inq[t]=0;
      for()
    }
    if(p[e]<0) return 0;
    return max_flow();
  };
  while(1){
    int k = spfa();
    if(!k) break;
    r += k;
  }
  cout<<r<<'\n'<<cost;
}
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,m);
  nf(n,m);
}