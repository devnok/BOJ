#include<iostream>
#include<queue>
#include<functional>
#include<vector>
#include<tuple>
#include<string.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
const int MAXN = 300030;
const ll INF = (1LL<<63)-1LL;
ll n,s[MAXN],p[MAXN],dist[MAXN],psum[MAXN];
int main(){
    cin>>n;
    fill(dist,dist+n,INF);
    for(ll a,i=1;i<n;i++){
        cin>>a;
        psum[i] = psum[i-1]+a;
    }
    for(ll i=0;i<n-1;i++){
        cin>>p[i]>>s[i];
    }
    priority_queue<pll,vector<pll>,greater<pll> > pq;
    pq.push({0,0});
    ll here,d;
    while(!pq.empty()){
        tie(d,here) = pq.top(); pq.pop();
        if(here == n-1){
            cout<<dist[here];
            return 0;
        }
        if(dist[here] < d) continue;
        for(int i=here+1;i<n;i++){
            ll D = d+p[here]+s[here]*(psum[i]-psum[here]);
            if(D<dist[i]){
                pq.push({D,i});
                dist[i] = D;
            }
        }
    }
}