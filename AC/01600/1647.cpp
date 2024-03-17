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

const int MAXN = 100010;
int par[MAXN];

void init(int n){
    for(int i=0;i<=n;i++) par[i]=i;
}
int find(int x){
    return par[x] = x==par[x]?x:find(par[x]);
}
void uni(int p,int q){
    par[find(p)] = par[find(q)];
}

struct Edge {
    int u,v,w;
    bool operator<(const Edge& rhs) const {
        return w<rhs.w;
    }
};

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<Edge> e(m);
    for(auto& [u,v,w]:e) cin>>u>>v>>w;
    sort(all(e));

    int k=0, ans=0;;

    init(n);
    for(auto [u,v,w]: e){
        if(k+2 == n) break;
        int pu = find(u);
        int pv = find(v);
        if(pu != pv){
            uni(pu, pv);
            ans += w;
            k++;
        }
    }
    cout<<ans;
}