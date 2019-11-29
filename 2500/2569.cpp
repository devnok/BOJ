#include<iostream>
#include<vector>
#include<string>
using namespace std;

int dp[301][2];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int num[301],n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>num[i];
    dp[0][0] = num[0];
    dp[1][0] = num[1];
    dp[1][1] = num[0] + num[1];
    for(int i=2;i<n;i++){
        dp[i][0] = max(dp[i-2][1],dp[i-2][0]) + num[i];
        dp[i][1] = dp[i-1][0] + num[i];
    }
    cout<<max(dp[n-1][0],dp[n-1][1]);
}