#include<iostream>
using namespace std;

int n,a[20],dp[1<<16][41][2],m[1<<16];
int main(){
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  dp[0][0][0] = dp[0][0][1] = 1;
  int all = (1<<n)-1;
  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<=40;j++){
      for(int k=0;k<n;k++){
        if(i>>k&1) continue;
        dp[i+(1<<k)][j+a[k]][0] |= dp[i][j][0];
      }
    }
  }
  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<=40;j++){
      if(!dp[i][j][0]) continue;
      if(dp[i][j][1]) m[i] = max(m[i], j);
      for(int k=0;k<n;k++){
        if(i>>k&1) continue;
        dp[i+(1<<k)][j+a[k]][1] |= dp[i][j][1];
      }
    }
  }
  int ans=0;
  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<=40;j++){
      if(dp[i][j][1]) ans = max(ans, j*m[all-i]), printf("%d %d\n",j,m[all-i]);
    }
  }
  cout<<ans;
}