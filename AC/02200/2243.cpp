#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <bitset>
#include <functional>
#include <chrono>
#include <random>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#define all(v) (v).begin(), (v).end()
#define cpr(v) sort(all(v)); (v).erase(unique(all(v)), (v).end())
#define idx(v, x) int(lower_bound(all(v), (x)) - (v).begin())
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);
#define INF 1000000000
template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }
struct formoontree{
  vint tree;
  int sz;
  formoontree(int n) {sz=1; while(sz<n) sz*=2; tree.resize(sz*2,0);}
  void init(int n){
    for(int x,i=1; i<=n; i++){
      x=i;
      tree[x+=sz]=i;
      for(x/=2; x; x/=2) tree[x]=tree[2*x]+tree[2*x+1];
    }
  }
  int get(int a, int b){
    int r=1;
    for(a+=sz,b+=sz; a<=b; a/=2,b/=2){
      if(a%2==1) r+=tree[a++];
      if(b%2==0) r-=tree[b--];
    }
    return r;
  }
  void update(int idx, int val){
    tree[idx+=sz]+=val;
    for(idx/=2; idx; idx/=2) tree[idx]=tree[2*idx]+tree[2*idx+1];
  }
  int grade(int k){
    int node;
    for(node=1; node<tree.size(); node*=2){
      if(tree[node]<k){
        k-=tree[node];
        node++;
      }
    }
    return node/2-sz;
  }
};
int main(){
  cin.tie(0)->sync_with_stdio(0);
  ints(n);
  formoontree tree(1000001);
  while(n--){
    ints(a);
    if(a==1){
      ints(k);
      int p=tree.grade(k);
      cout<<p<<"\n";
      tree.update(p,-1);
    }else{
      ints(p,q);
      tree.update(p,q);
    }
  }
}