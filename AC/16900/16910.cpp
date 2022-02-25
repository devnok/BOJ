#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

using ll = long long;
using vint = vector<int>;

#define all(v) (v).begin(), (v).end()
#define cpr(v) sort(all(v)); (v).erase(unique(all(v)), (v).end())
#define idx(v, x) int(lower_bound(all(v), (x)) - (v).begin())

const int sz = 1<<19;

struct Seg{
  int dat[2*sz], z[2*sz];
  const int INF = 1e9;
  void build(int n){
    for(int i=sz;i<2*sz;i++) dat[i] = INF;
    for(int i=0;i<n;i++){
      dat[i+sz] = i;
    }
    for(int x=sz-1;x;x--){
      dat[x] = min(dat[2*x], dat[2*x+1]);
    }
  }
  void push(int x,int l,int r){
    if(z[x]==1){
      dat[x] = INF;
      if(x<sz) z[2*x] = z[2*x+1] = 1;
    }
    if(z[x]==2){
      dat[x] = l;
      if(x<sz) z[2*x] = z[2*x+1] = 2;
    }
    if(z[x]==3){
      if(x<sz){
        z[2*x] = 3-z[2*x];
        z[2*x+1] = 3-z[2*x+1];
        push(2*x,l,(l+r)/2);
        push(2*x+1,(l+r)/2+1,r);
        dat[x] = min(dat[2*x],dat[2*x+1]);
      }
      else dat[x] = dat[x]==l ? INF : l;
    }
    z[x]=0;
  }
  void update(int x,int l,int r,int s,int e,int t){
    push(x,l,r);
    if(e<l || r<s) return;
    if(s<=l && r<=e){
      z[x] = t;
      push(x,l,r);
      return;
    }
    int mid = (l+r)/2;
    update(2*x,l,mid,s,e,t);
    update(2*x+1,mid+1,r,s,e,t);
    dat[x] = min(dat[2*x],dat[2*x+1]);
  }
  void update(int s,int e,int t){update(1,0,sz-1,s,e,t);}
} S;

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin>>n;
  vector<ll> a = {1};
  vector<tuple<int,ll,ll>> qs(n);
  for(auto& [q,l,r]:qs){
    cin>>q>>l>>r;
    a.push_back(l);
    if(l>1) a.push_back(l-1);
    a.push_back(r); a.push_back(r+1);
  }
  cpr(a);
  S.build(a.size());
  for(auto [q,l,r]:qs){
    int s=idx(a,l), e=idx(a,r);
    S.update(s,e,q);
    cout<<a[S.dat[1]]<<'\n';
  }
}