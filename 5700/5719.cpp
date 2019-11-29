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
    for(int i=1;i<=N;i++)
        for(int j=0;j<2;j++)
            e[j][i] = e[j][i-1]*p%K[j];
    for(int i=0;i<N;i++)
        for(int j=0;j<2;j++)
            ha[j][i] = ((i?ha[j][i-1]:0) + s[i]*e[j][N-i])%K[j]; // p^N-1 ~ p^0
}
bool decision(int l){
    ma.clear();
    int i;
    ll h = H(ha[0][l-1],ha[1][l-1]),h1; // p^(N-l+1) ~ p^N
    ma[h]=1;
    for(i=l;i<N;i++){
        h = (ha[0][i]-ha[0][i-l]+K[0])%K[0]*e[0][i-l+1]%K[0]; // p^(N-i) ~ p^(N-i+l-1) * p^(i-l+1)
        h1 = (ha[1][i]-ha[1][i-l]+K[1])%K[1]*e[1][i-l+1]%K[1];
        ll t = H(h,h1);
        auto k = ma.find(t);
        if(k != ma.end()) return true;
        ma[t]=1;
    }
    return false;
}
int main(){
    cin>>N;
    cin>>S;
    N = S.length();
    e[0][0]=e[1][0]=1;
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
    cout<<lo;
}
/*
banana
a 676284101 869638617
n 591662381 -1599144379
a 676284101 869638617
n 591662381 609335631
a 676284101 869638617
*/