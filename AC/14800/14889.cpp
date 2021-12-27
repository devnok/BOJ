#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

const int all = (1<<20)-1;
int c[21][21],ans=1e9,n,i,j,dp[21][all+1],k;
void dfs(int x,int s,int p){
    if(p+p==n){
        int r1=0,r2=0,ns=all-s;
        for(k=0;k<n;k++){
            if((s>>k)&1) r1+=dp[k][s];
            else r2+=dp[k][ns];
        }
        ans = min(ans,abs(r1-r2));
    }
    for(int i=x;i<n;i++)
        dfs(i+1,s+(1<<i),p+1);
}
int main(){
    cin>>n;
    for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>c[i][j];
    for(i=0;i<n;i++) for(j=0;j<all;j++){
        for(k=0;k<n;k++){
            if((j>>k)&1) dp[i][j] += c[i][k];
        }
    }
    dfs(0,0,0);
    cout<<ans;
}