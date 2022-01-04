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
#include <list>
#define INF 987654321
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
#define cpr(v) sort(all(v)); (v).erase(unique(all(v)), (v).end())
#define idx(v, x) int(lower_bound(all(v), (x)) - (v).begin())
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int n,m;
ll dp[101][101];
int dp2[101][101];
int adj[101][101];
int main(){
  //cin.tie(0)->sync_with_stdio(0);
  cin>>n>>m;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      dp[i][j]=INF;
      dp2[i][j]=-1;
    }
    dp[i][i]=0;
  }
  while(m--){
    ints(a,b);
    ll c; cin>>c;
    dp[a][b]=min(dp[a][b],c);
    adj[a][b] = dp[a][b];
  }
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(dp[i][j]>dp[i][k]+dp[k][j]){
          dp2[i][j]=k;
        }
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(dp[i][j]==INF || dp[i][j]==0) dp2[i][j]=0;
      cout<<(dp[i][j]==INF ? 0 :dp[i][j])<<" ";
    }
    cout<<'\n';
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      vint ans;
      if(dp[i][j]==INF || i==j){
        cout<<"0\n";
        continue;
      }
      int h=i;
      while(1){
        ans.push_back(h);
        if(h==j) break;
        for(int k=1;k<=n;k++){
          if(k!=h){
            if(adj[h][k] && adj[h][k] + dp[k][j] == dp[h][j]){
              h=k;
              break;
            }
          }
        }
      }
      cout<<ans.size()<<" ";
      for(auto a :ans)
        cout<<a<<" ";
      cout<<'\n';
    }
  }
}