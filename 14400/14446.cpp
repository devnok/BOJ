#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 100010;
int n,l[MAXN],r[MAXN],i,p,idx;
vector<int> child[MAXN],ans;
vector<pair<int,int>> rate;
void dfs(int x){
    static int c=0;
    l[x]=++c;
    for(int i=0;i<child[x].size();i++){
        dfs(child[x][i]);
    }
    r[x]=c;
}
struct BIT{
    int dat[MAXN];
    void update(int x){for(;x<=n;x+=x&-x) dat[x]++; }
    int get(int x){int r=0;for(;x;x-=x&-x) r+=dat[x]; return r;}
    int get(int s,int e){return get(e)-get(s-1);}
} B;
int main(){
    cin>>n;ans.resize(n);rate.resize(n);
    for(auto& j:rate)
        scanf("%d",&j.first),j.second=++i;
    for(i=1;i<n;child[p].push_back(++i))
        scanf("%d",&p);
    dfs(1);
    sort(rate.begin(),rate.end());
    for(i=n;i>0;i--){
        idx=rate[i-1].second;
        ans[idx-1]=B.get(l[idx],r[idx]);
        B.update(l[idx]);
    }
    for(int i:ans)
        printf("%d\n",i);
}