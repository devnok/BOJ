#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)

int n,i,c[35][35],ans=1000;
vector<string> b;

void reverse(int k,int reversed){ // k열 뒤집기
    if(k==n){
        int i,j,ret=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                c[i][j] = b[i][j] == 'T';
                c[i][j] ^= (reversed>>i)&1;
            }
        }
        for(j=0;j<n;j++){
            int cnt=0;
            for(i=0;i<n;i++)
                cnt += c[i][j];
            ret += min(n-cnt,cnt);
        }
        ans = min(ret,ans);
        return;
    }
    reverse(k+1,reversed+(1<<k));
    reverse(k+1,reversed);
}
int main(){
    cin>>n; b.resize(n);
    for(auto& s:b) cin>>s;
    reverse(0,0);
    cout<<ans;
}