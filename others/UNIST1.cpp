#include<bits/stdc++.h>
using namespace std;

using ll = long long;
string S;
int lo,hi,N,s[200020];
ll e[2][200020],ha[2][200020];
const ll K[2] = {1000000009,1000000021};
const ll p = 10007;
unordered_map<ll,int> ma;
inline ll H(ll x,ll y){ return x*K[1]+y;}
void init(){
    e[0][0]=e[1][0]=1;
    for(int i=1;i<=N;i++)
        for(int j=0;j<2;j++)
            e[j][i] = e[j][i-1]*p%K[j];
    for(int i=0;i<N;i++)
        for(int j=0;j<2;j++)
            ha[j][i] = ((i?ha[j][i-1]:0) + s[i]*e[j][N-i])%K[j]; // p^N-1 ~ p^0
}
bool decision(int l){
    ma.clear();
    vector<ll> vh(N-l+1),vh1(N-l+1);
    ll h=0,h1=0;
    int i;
    vh[0]=ha[0][l-1];
    vh1[0]=ha[1][l-1];
    for(i=l;i<N;i++){
        vh[i-l+1]=(ha[0][i]-ha[0][i-l]+K[0])%K[0]*e[0][i-l+1]%K[0];
        vh1[i-l+1]=(ha[1][i]-ha[1][i-l]+K[1])%K[1]*e[1][i-l+1]%K[1];
    }
    for(i=l;i<=N-l;i++){
        ll t = H(vh[i],vh1[i]);
        if(ma.find(t) == ma.end()) ma[t]=0;
        ma[t]++;
    }
    for(i=0;i+l<=N;i++){
        if(i>=l){
            ll t = H(vh[i-l],vh1[i-l]);
            if(ma.find(t) == ma.end()) ma[t]=0;
            ma[t]++;
        }
        auto k = ma.find(H(vh[i],vh1[i]));
        if(k != ma.end()) return true;
        if(i+2*l<=N){
            ll t = H(vh[i+l],vh1[i+l]);
            ma[t]--;
            if(!ma[t]) ma.erase(t);
        }
    }
    return false;
}
int main(){
    cin>>S;
    N = S.length();
    for(int i=0;i<N;i++){
        s[i] = S[i];
    }
    init();
    lo=0,hi=N;
    while(lo+1<hi){
        int mid = (lo+hi)/2;
        if(decision(mid)) lo=mid;
        else hi=mid;
    }
    cout<<lo-!lo;
}