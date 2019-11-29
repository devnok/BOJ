#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;
ll dp[11][10], ans;
void rdp(ll cnt,int i,int j){
    ans=ans*10+j;
    if(i==1) return;
    for(int k=0;k<10;k++){
        if(cnt>dp[i-1][k]) cnt-=dp[i-1][k];
        else{
            rdp(cnt,i-1,k);
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll n; cin>>n;
    n+=1;
    for(int i=0;i<10;i++) dp[1][i]=1;
    for(int i=2;i<11;i++){
        for(int j=1;j<10;j++){
            for(int k=0;k<j;k++){
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    int i,j;
    for(i=1;i<11;i++){
        for(j=0;j<10;j++){
            if(n>dp[i][j]) n-=dp[i][j];
            else{
                rdp(n,i,j);
                cout<<ans;
                return 0;
            }
        }
    }
    cout<<-1;
}