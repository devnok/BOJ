#include<iostream>
#include<vector>
#include<string>
using namespace std;

int a[53][53],n,m,mod,d[53][53],dp[2501][2501],tr[2501][2501];
void track(int t,int c){
    if(!t) return;
    int x=(t-1)/m+1;
    int y=(t-1)%m+1;
    if((a[x][y]<0&&tr[t][c])||a[x][y]>0){
        a[x][y]=1;
        return track(t-1,(c-d[x][y]+mod)%mod);
    }
    a[x][y]=0;
    track(t-1,c);
}
int main(){
    cin>>n>>m>>mod;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            d[i][j] = (n-i+1)*(m-j+1)*i*j%mod;
            int t=(i-1)*m+j;
            for(int c=0;c<mod;c++){
                dp[t][c] = (a[i][j]<=0?dp[t-1][c]:0) | (a[i][j]?dp[t-1][(c-d[i][j]+mod)%mod]:0);
                tr[t][c] = !dp[t-1][c];
            }
        }
    }
    if(dp[n*m][0]){
        puts("1");
        track(n*m,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else puts("-1");
}