#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 1000010;
using ll = long long;
int m,q,a=1,b=1,c,idx;
ll n,ps[MAXN],f[MAXN];
ll digit(ll num){
    return num<100?num<10?1:2:3;
}
int main(){
    cin>>q>>m;
    do{
        f[++c]=a;
        ps[c]=ps[c-1]+digit(f[c]);
        int tmp=a;
        a=b; b=(b+tmp)%m;
    }while(!(a==1&&b==1));
    while(q--){
        scanf("%lld",&n);
        n=(n+ps[c]-1)%ps[c]+1;
        idx=lower_bound(ps,ps+c+1,n)-ps;
        printf("%c\n",to_string(f[idx])[n-ps[idx-1]-1]);
    }
}