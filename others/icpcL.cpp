#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
using ll = long long;

const int INF = 987654321;
int n,a[251],b[251],S,dp[62501],ans=INF;
int main() {
    cin>>n;
    fill(dp,dp+62501,INF);
    for(int i=0;i<n;i++) cin>>a[i]>>b[i],S+=a[i];
    dp[S]=0;
    for(int i=0;i<n;i++){
        for(int j=a[i];j<=S;j++){
            dp[j-a[i]] = min(dp[j-a[i]],dp[j]+b[i]);
        }
    }
    for(int i=0;i<=S;i++){
        ans = min(ans,max(dp[i],i));
    }
    cout<<ans;
}