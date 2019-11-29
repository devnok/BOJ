#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

typedef pair<int,int> pii;
typedef long long int lld;
typedef unsigned ud;

const int MAXN = 300030;
const int MAXC = 10010;
int n,c;
int p[MAXN],m;
vector<int> caps[MAXC];

struct RNG{
    ud v=29140681u;
    ud next(){
        const ud seed=57527u;
        v=v*seed%100000007;
        return v;
    }
} rng;
int lb(vector<int>& v,int s,int e){
    return lower_bound(v.begin(),v.end(),e+1)-lower_bound(v.begin(),v.end(),s);
}
int query(int a,int b){
    int cnt=(b-a+1);
    for(int i=0;i<100;i++){
        int s=a+rng.next()%cnt;
        if(lb(caps[p[s]],a,b) * 2 > cnt)
            return p[s];
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        caps[p[i]].push_back(i);
    }
    cin>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        int ans=query(a,b);
        if(ans==-1) cout<<"no\n";
        else{
            cout<<"yes "<<ans<<"\n";
        }
    }
}