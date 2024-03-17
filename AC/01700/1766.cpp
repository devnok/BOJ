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

const int MAXN = 33000;
vint adj[MAXN];
int v[MAXN], st[MAXN], ind[MAXN];

void dfs(int x){
    static int c=0;
    v[x]=1;
    for(int i:adj[x]) if(!v[i]) dfs(i);
    st[c++] = x;
}

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int a,b,i=0;i<m;i++) {
        cin>>a>>b;
        adj[a].push_back(b);
        ind[b]++;
    }
    // for(int i=1;i<=n;i++) sort(all(adj[i]), greater<int>());
    priority_queue<int, vint, greater<int>> pq;
    for(int i=n;i;i--) {
        if(!ind[i]) pq.push(i);
    }
    while(!pq.empty()) {
        int x=pq.top(); pq.pop();
        cout<<x<<" ";
        for(int i:adj[x]) {
            ind[i]--;
            if(!ind[i]) pq.push(i);
        }
    }
}