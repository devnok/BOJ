#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef long long int lld;
const int MAXN = 10000010;
int pa[MAXN],ans;
vector<lld> pn;
lld a,b;
void eratosthenes(){
    for(lld i=2;i*i<=b;i++){
        if(pa[i]) continue;
        pn.push_back(i);
        for(lld j=2*i;j*j<=b;j+=i) pa[j]=1;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>a>>b;
    eratosthenes();
    for(lld p:pn){
        lld num=p;
        while(num <= b/p){
            if(num*p >= a) ans++;
            num *= p;
        }
    }
    cout<<ans;
}