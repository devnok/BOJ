#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;
const int K = 100030001;
ll dp[301][301],sum[301];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n,l;
    cin>>n>>l;
    sum[0]=dp[1][1]=1;
    for(int i=2;i<=l;i++){
        for(int j=2;j<=n;j++){
            for(int k=1;k<j;k++){
                dp[i][j]=(dp[i][j]+dp[i-1][k]*sum[j-k-1])%K;
            }
            dp[i][j]=(dp[i][j]*2)%K;
            for(int k=1;k<j;k++) dp[i][j]=(dp[i][j]+dp[i-1][k]*dp[i-1][j-k-1])%K;
        }
        for(int j=1;j<=n;j++) sum[j]=(sum[j]+dp[i-1][j])%K;
    }
    cout<<dp[l][n];
}