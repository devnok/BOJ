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
int v[MAXN], s[MAXN];
vint adj[MAXN];
void dfs(int x){
  if(s[x]) return;
  int c=0;
  v[x]=1;
  for(int i:adj[x]){
    if(!v[i]){
      dfs(i);
      c++;
    }
  }
  v[x]=0;
  if(!c){
    puts("yes");
    exit(0);
  }
}
int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,m);
  for(int i=0;i<m;i++){
    ints(u,v);
    adj[u].push_back(v);
  }
  ints(sn);
  while(sn--){
    ints(p);
    s[p]=1;
  }
  dfs(1);
  puts("Yes");
}