#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
ll n,arr[100010],m;

ll labs(ll num){
    return num<0?-num:num;
}
ll calc(ll k){
    ll ret=0;
    for(int i=0;i<n;i++) ret += labs(arr[i]-k*i);
    return ret;
}
int main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    for(ll s=0,e=arr[n-1],i=0;i<100;i++){
        m = (s+e) >> 1;
        if(calc(m+1) < calc(m)){
            s=m+1;
        } else {
            e=m;
        }
    }
    printf("%lld",calc(m));
}