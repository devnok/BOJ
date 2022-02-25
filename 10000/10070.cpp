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

struct Seg{
  vpii z;
  int sz;
  void init(int n){
    sz=1; while(sz<n) sz*=2;
    z.resize(2*sz, {0, 1e9});
  }
  void push(int x,int op,int v){
    if(op==1){
      z[x].x = max(z[x].x, v);
      z[x].y = max(z[x].y, v);
    }
    else {
      z[x].x = min(z[x].x, v);
      z[x].y = min(z[x].y, v);
    }
  }
  void update(int x,int l,int r,int s,int e,int op, int v){
    if(r<s||l>e) return;
    if(s<=l && r<=e){
      push(x,op,v);
      return;
    }
    push(2*x, 1, z[x].x);
    push(2*x, 2, z[x].y);
    push(2*x+1, 1, z[x].x);
    push(2*x+1, 2, z[x].y);
    z[x] = {0, 1e9};
    int mid = (l+r)/2;
    update(2*x,l,mid,s,e,op,v);
    update(2*x+1,mid+1,r,s,e,op,v);
  }
  void update(int s,int e,int op, int v){update(1,0,sz-1,s,e,op,v);}
  int get(int x){return z[x+sz].x;}
} S;

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  ints(n,k);
  S.init(n);
  while(k--){
    ints(q,l,r,h);
    S.update(l,r,q,h);
  }
  for(int i=0;i<n;i++) S.update(i,i,1,0);
  for(int i=0;i<n;i++) cout<<S.get(i)<<'\n';
}
