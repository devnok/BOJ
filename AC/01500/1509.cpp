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

int dp[2525], p[5050];

void manacher(string s) {
    int n = s.size();
    string ss(2*n+1, '#');
    for(int i=0;i<n;i++) ss[2*i+1] = s[i];
    n = ss.size();

    int r=0,c=0;
    for(int i=0;i<n;i++) {
        p[i] = min(r-i, p[2*c-i]);
        while(i-p[i]-1 >= 0 && i+p[i]+1 < n && ss[i-p[i]-1] == ss[i+p[i]+1]) p[i]++;
        if(r<i+p[i]) {
            c=i;
            r=i+p[i];
        }
    }
}

int is_pal(string s, int i, int j) {
    if(i==j) return 1;
    int l = j-i+1;
    return p[i+j+1] >= l;
}

int solve(string s) {
    manacher(s);
    int n = s.size();
    dp[0]=1;
    for(int i=1;i<n;i++) {
        dp[i] = i+1;
        if(is_pal(s, 0, i)) dp[i]=1;
        else for(int j=0;j<i;j++) {
            if(is_pal(s, j+1, i)) dp[i] = min(dp[i], dp[j]+1);
        }
        cout<<dp[i]<<endl;
    }
    return dp[n-1];
}

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>s;
    cout<<solve(s);
}