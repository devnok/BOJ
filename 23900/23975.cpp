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

const int MAXN = 1000100;
int a[MAXN],d[MAXN];
vpii adj[MAXN];

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,m,k);
  for(int i=0;i<n;i++) cin>>a[i];
  for(int u,v,c,i=0;i<m;i++){
    cin>>u>>v>>c;
    adj[u].push_back({v, c*1000+a[v]});
    adj[v].push_back({u, c*1000+a[u]});
  }
  const int INF = 987654321;
  priority_queue<pii, vpii, greater<pii>> pq;
  pq.push({0, 1});
  fill(d, d+1+n, INF);
  d[1] = 0;
  while(!pq.empty()){
    auto [dist,u] = pq.top(); pq.pop();
    if(d[u] < dist) continue;
    for(auto [v,w]: adj[u]){
      if(d[v] > dist + w){
        d[v] = dist+w;
        pq.push({d[v], v});
      }
    }
  }
  cout<<d[n];
}