#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;
ll n,ans;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n; ans=n;
    for(ll i=1;i*i<=n-1;i++){
        ans += (n-1)/i;
        if((i+1)*(i+1)<=n-1 || (i+1)*i<=n-1)
            ans += ((n-1)/i-(n-1)/(i+1)) * i;
    }
    cout<<ans;
}