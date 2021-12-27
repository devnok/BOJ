#include<iostream>
#include<queue>
#include<map>
#include<string.h>
using namespace std;

using ll = long long;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll a,b;
    cin>>a>>b;
    queue<ll> q;
    map<ll,ll> m;
    q.push(a);
    while(!q.empty()){
        ll h = q.front(); q.pop();
        if(h==b){
            cout<<m[h]+1;
            return 0;
        }
        for(auto num:{h*2,h*10+1}){
            if(num>1e9 || num>b) continue;
            q.push(num);
            m[num]=m[h]+1;
        }

    }
    puts("-1");
}