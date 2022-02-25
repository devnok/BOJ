#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using vint = vector<int>;
const int INF = 987654321;
const int MAXN = 151;

int n,m,dp[MAXN][MAXN],sz[MAXN],ans=INF;

vint adj[MAXN];

int dfs(int x,int p){
  sz[x] = 1;
  dp[x][1]=0;
  for(int i:adj[x]){
    if(i^p){
      int s=dfs(i,x);
      for(int j=sz[x]+s;j;j--){
        dp[x][j]++;
        for(int k=min(s,j);k;k--){
          // printf("%d,%d => %d,%d\n",j,k,dp[i][k],dp[x][j-k]);
          dp[x][j] = min(dp[x][j], dp[i][k]+dp[x][j-k]);
        }
        // printf("%d->%d->%d %d: %d\n",p,x,i,j,dp[x][j]);
      }
      sz[x] += s; 
    }
  }
  ans = min(ans, dp[x][m]+(p!=0));
  return sz[x];
}
int main(void){
  cin>>n>>m;
  for(int a,b,i=1;i<n;i++) {
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      dp[i][j] = INF;
  dfs(1,0);
  cout<<ans;
}