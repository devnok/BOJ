#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;
const ll K = 1000000009;
const int MAXN = 100010;
ll a[MAXN],ans;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n; cin>>n;
    for(int num,i=0;i<n;i++){
        cin>>num; a[num]=(a[num]+num)%K;
    }
    static ll sum1, sum2;
    for(int i=1;i<=100000;i++){
        ans = (ans+sum2*a[i])%K;
        sum2 = (sum2+sum1*a[i])%K;
        sum1 = (sum1+a[i])%K;
    }
    cout<<ans;
}