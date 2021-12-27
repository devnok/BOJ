#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN = 10010;
const int INF = 987654321;
int dp[MAXN],n,m,arr[MAXN];

int sumof(int s,int e){
    return abs(arr[s])+abs(arr[e])+arr[e]-arr[s];
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);
    fill(dp,dp+n+1,INF);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=m&&i+j<=n;j++){
            dp[i+j] = min(dp[i+j],dp[i]+sumof(i+1,i+j));
        }
    }
    cout<<dp[n]-max(abs(arr[1]),abs(arr[n]));
}