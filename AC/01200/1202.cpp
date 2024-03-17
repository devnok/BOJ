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

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  int n,k;
  cin>>n>>k;

  vint c(k);
  vpii a(n); // M, V
  for(auto& [x,y]:a) cin>>x>>y;
  for(auto& i:c) cin>>i;
  
  sort(all(a));
  sort(all(c));

  priority_queue<int> pq;

  ll j=0, ans=0;
  for(int i=0;i<k;i++) {
    while(j<n && a[j].x <= c[i]){
      pq.push(a[j++].y);
    }
    if(!pq.empty()){
      ans += pq.top();
      pq.pop();
    }
  }
  cout<<ans;
}
/*
작은거부터?
담을수있는지 없는지 알아야됨
담을수있는 최대 용량이 있음.

*/
