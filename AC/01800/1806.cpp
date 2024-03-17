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

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n,s;
    cin>>n>>s;
    vint v(n+1), p(n+1, 0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        p[i] = p[i-1] + v[i];
    }
    int ans=987654321;
    for(int i=1;i<=n;i++){
        int a = upper_bound(p.begin(), p.end(), p[i]-s) - p.begin();
        if(a<1) continue;
        ans = min(ans, i-a+1);
        // cout<<t<<endl;
    }
    if(ans>n) cout<<0;
    else cout<<ans;
}