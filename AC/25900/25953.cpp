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
using ti3 = tuple<int,int,int>;

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

const int INF = 1987654321;

vector<ti3> adj[10010];
int dist[1010][10010];

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,t,m,s,e);
  for(int i=0;i<t;i++){
    for(int j=0;j<n;j++) dist[i][j] = INF;
    for(int j=1;j<=m;j++){
      ints(u,v,w);
      adj[u].emplace_back(i,v,w);
      adj[v].emplace_back(i,u,w);
    }
  }
  priority_queue<ti3,vector<ti3>,greater<ti3>> pq;
  pq.emplace(0,-1,s); // weight, time, here
  while(!pq.empty()){
    int w,t,h;
    tie(w,t,h) = pq.top(); pq.pop();
    printf("%d: here: %d, weight: %d\n",t,h,w);
    if(h==e){
      cout<<w;
      return 0;
    }
    int k = lower_bound(adj[h].begin(), adj[h].end(), tuple<int,int,int>(t+1,0,0)) - adj[h].begin();
    for(int i=k;i<sz(adj[h]);i++){
      int _t,next,_w;
      tie(_t,next,_w) = adj[h][i];
      if(dist[_t][next] > w + _w) {
        dist[_t][next] = w+_w;
        pq.emplace(dist[_t][next], _t, next);
      }
    }
  }
  puts("-1");
}