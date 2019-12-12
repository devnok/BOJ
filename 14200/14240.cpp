#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200020;
using ll = long long;
int n,i;
ll a[MAXN],p[MAXN],s[MAXN],dp[MAXN],ans;
ll la[MAXN],lb[MAXN],S;
double cross(int x,int y){return (double)(lb[x]-lb[y])/(la[y]-la[x]);}
void insert(ll x,ll y){
    la[S]=x,lb[S]=y;
    while(S>1&&cross(S,S-1)>=cross(S-1,S-2)){
        la[S-1]=la[S];
        lb[S-1]=lb[S]; S--;
    } S++;
}
ll query(ll x){
    int s=0,e=S-1,mid;
    while(s<e){
        mid=(s+e)/2;
        if(cross(mid,mid+1)>=x) s=mid+1;
        else e=mid;
    }
    return x*la[s]+lb[s];
}
int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        scanf("%lld",a+i);
        s[i]=s[i-1]+a[i]*i;
        p[i]=p[i-1]+a[i];
    } insert(0,0);
    for(i=1;i<=n;i++){
        ans=max(ans,dp[i]=query(p[i])+s[i]);
        insert(-i,i*p[i]-s[i]);
    }
    cout<<ans;
}