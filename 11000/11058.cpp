#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

long long dp[101],dp2[101][101];
int main(){
    int n;
    cin>>n;
    dp[1] = dp2[1][0] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp2[i][j] = max(dp2[i-1][j]+1, dp[j]*(i-j-1));
            dp[i] = max(dp[i], dp2[i][j]);
        }
    }
    cout<<dp[n];
}