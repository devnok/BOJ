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

int b[15][15], n;
int dp[20][1<<20];
int solve(int ln, int r){
    if(ln==2*n-1) return 0;
    int& ret = dp[ln][r];
    if(~ret) return ret;
    ret = solve(ln+1, r);
    for(int x=0;x<n;x++){
        int y = ln - x;
        if(y<0||y>=n||!b[x][y]) continue;
        int rr = x-y+n-1;
        if((r>>rr) & 1) continue;
        ret = max(ret, solve(ln+1, r|(1<<rr))+1);
    }
    return ret;
}
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>b[i][j];
    cout<<solve(0, 0);
}
/*
10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
*/