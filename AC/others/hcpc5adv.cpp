#include<cstdio>
using ll = unsigned long long;
const ll a = (1ull<<64)-1;
int h(ll x){return 64-__builtin_clzll(x);}
int main(){
    while(1){
        ll x;
        scanf("%llu",&x);
        printf("h(%llu) = %d\n",x,h(x));
    }
}