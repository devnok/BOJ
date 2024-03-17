#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

using vint = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

#define x first
#define y second
#define all(v) (v).begin(), (v).end()

const int K = 1'000'000'000;

int dp[11][101][1<<10];

void add(int& d, int v){ d = (d+v) % K; }

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<10;i++) dp[i][1][1<<i] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<10;j++) {
            for(int k=0;k<(1<<10);k++){
                if(j>0){
                    int kk = k|(1<<(j-1));
                    add(dp[j-1][i+1][kk], dp[j][i][k]);
                }
                if(j<9){
                    int kk = k|(1<<(j+1));
                    add(dp[j+1][i+1][kk], dp[j][i][k]);
                }
            }
        }
    }
    
    int ans=0, f = (1<<10) - 1;
    for(int j=1;j<10;j++) ans = (ans+dp[j][n][f])%K;
    cout<<ans;
}