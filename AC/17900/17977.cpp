#include<bits/stdc++.h>
using namespace std;

int dp[1001000];
int main(){
    int n; cin>>n;
    dp[3]=0;dp[4]=1;
    for(int i=5;i<=n;i++)
        dp[i] = dp[(i+1)/2]+2;
    cout<<dp[n];
}