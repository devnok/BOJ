#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long int lld;
const int MAXN = 1501;
const int INF = 987654321;

int n,adj[MAXN][MAXN],dp[MAXN][MAXN],ans=INF;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>adj[i][j];
    }
    fill(&dp[0][0],&dp[n][n],INF);
    dp[1][2]=adj[1][2];
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[j][i+1] = min(dp[j][i+1],dp[j][i]+adj[i][i+1]);
            dp[i][i+1] = min(dp[i][i+1],dp[j][i]+adj[j][i+1]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    for(int i=1;i<n;i++) ans = min(ans,dp[i][n]);
    cout<<ans;
}