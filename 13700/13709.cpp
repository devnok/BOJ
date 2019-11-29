#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

typedef unsigned long long ll;
const int MAXN=100010;
const ll A = (1ull<<64-1)>>63;
ll n,a[MAXN],ps[MAXN],ans;
int trie[MAXN*64][2],cnt[MAXN][2],piv;
void add(int p,ll x,int d){
    if(d<0) return;
    int v = (x>>d)&1;
    if(!trie[p][v])
        trie[p][v] = ++piv;
    cnt[p][v]++;
    add(trie[p][v],x,d-1);
}
ll query(int p,int d){
    if(d<0) return 0;
    if(cnt[p][1]&1)
        return query(trie[p][1],d-1)+(1ull<<d);
    else
        return query(trie[p][0],d-1);
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T; T=1;
    while(T--){
        a[0]=piv=0;
        memset(trie,0,sizeof(trie));
        cin>>n;
        add(0,0,63);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]=a[i]^a[i-1];
            add(0,a[i],63);
        }
        ans=0;
        cout<<query(0,63);
    }
}