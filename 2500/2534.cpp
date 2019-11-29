#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

using ll = long long;
const int MAXN = 300030;
const ll K = 1e9+7;

vector<int> adj[MAXN],radj[MAXN];
ll m,M,n,k,p,in[MAXN][2],e[MAXN]={1};
int x,i;
int main(){
    cin>>n>>k>>p;
    for(i=1;i<k;i++)
        e[i]=e[i-1]*n%K;
    for(int a,b,i=0;i<p;i++){
        scanf("%d%d",&a,&b);
        radj[b].push_back(a);
        adj[a].push_back(b);
        in[a][0]++; in[b][1]++;
    }
    priority_queue<int,vector<int>,greater<int>> pq1,pq2;
    for(i=0;i<k;i++){
        if(!in[i][0])
            pq1.push(i);
        if(!in[i][1])
            pq2.push(i);
    }
    i=0;
    while(!pq1.empty()){
        x = pq1.top(); pq1.pop();
        M += (n-k+i) * e[x] % K;
        M%=K; i++;
        for(int nx:radj[x])
            if(!--in[nx][0]) pq1.push(nx);
    }
    i=k-1;
    while(!pq2.empty()){
        x = pq2.top(); pq2.pop();
        m += i * e[x] % K;
        m %= K; i--;
        for(int nx:adj[x])
            if(!--in[nx][1]) pq2.push(nx);
    }
    cout<<(M-m+K)%K;
}