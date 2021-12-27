#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

const int sz = 1 << 17;
const int MAXN = 100010;

struct MO{
    int cnt[MAXN],b[MAXN],p;
    void add(int x){
        b[cnt[x]]--;
        cnt[x]++;
        b[cnt[x]]++;
        p=max(p,cnt[x]);
    }
    void erase(int x){
        b[cnt[x]]--;
        if(p==cnt[x]&&!b[cnt[x]]) p--;
        cnt[x]--;
        b[cnt[x]]++;
    }
} mo;

struct query{
    int s,e,i;
    query():s(0),e(0),i(0){}
    query(int _s,int _e,int _i):s(_s),e(_e),i(_i){}
};
bool operator<(const query& a,const query& b){
    if(a.s/300 == b.s/300) return a.e < b.e;
    return a.s/300 < b.s/300;
}
int a[MAXN],n,m,ans[MAXN];
query qs[MAXN];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for(int s,e,i=0;i<m;i++){
        cin>>s>>e;
        qs[i]=query(s,e,i);
    }
    sort(qs,qs+m);
    mo.add(a[1]);
    for(int s=1,e=1,i=0;i<m;i++){
        int ns=qs[i].s,ne=qs[i].e;
        for(int j=s;j<ns;j++) mo.erase(a[j]);
        for(int j=ns;j<s;j++) mo.add(a[j]);
        for(int j=e+1;j<=ne;j++) mo.add(a[j]);
        for(int j=ne+1;j<=e;j++) mo.erase(a[j]);
        s=ns,e=ne;
        ans[qs[i].i] = mo.p;
    }
    for(int i=0;i<m;i++) cout<<ans[i]<<"\n";
}