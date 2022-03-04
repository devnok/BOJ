#include<vector>
using namespace std;

using ll = long long;

using vint = vector<int>;
using vll = vector<ll>;

// lazy-propagation segment tree
struct Seg{
  vint dat, z;
  int sz;
  void init(int n){
    sz=1; while(sz<n) sz*=2;
    dat.resize(2*sz,0);
    z.resize(2*sz,0);
  }
  void q(int& i,int v){ if(i<v) i=v; }
  void push(int x){
    q(dat[x], z[x]);
    if(x<sz){
      q(z[2*x], z[x]);
      q(z[2*x+1], z[x]);
    }
    z[x]=0;
  }
  void update(int x,int l,int r,int s,int e,int v){
    push(x);
    if(r<s||l>e) return;
    if(s<=l && r<=e){
      z[x]=v;
      push(x);
      return;
    }
    int mid = (l+r)/2;
    update(2*x,l,mid,s,e,v);
    update(2*x+1,mid+1,r,s,e,v);
    dat[x] = max(dat[2*x],dat[2*x+1]);
  }
  void update(int s,int e,int v){update(1,0,sz-1,s,e,v);}
  int get(int x,int l,int r,int s,int e){
    push(x);
    if(r<s||l>e) return 0;
    if(s<=l && r<=e) return dat[x];
    int mid = (l+r)/2;
    return max(
      get(2*x,l,mid,s,e),
      get(2*x+1,mid+1,r,s,e)
    );
  }
  int get(int s,int e){ return get(1,0,sz-1,s,e); }
} S;