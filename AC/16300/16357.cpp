#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
#define S first
#define E second

const int MAXN = 200010;
int n,ans;
pair<int,int> a[MAXN];
vector<int> ys;
const int sz = 1 << 18;
struct Seg{
    int mx[sz*2],lazy[sz*2];
    void push(int x,int len){
        mx[x] += lazy[x];
        if(len>1) lazy[2*x]+=lazy[x], lazy[2*x+1]+=lazy[x];
        lazy[x]=0;
    }
    int get(int s,int e,int x,int st,int len){
        push(x,len);
        if(e<st || st+len-1<s) return -1;
        if(s<=st && st+len-1<=e) return mx[x];
        len>>=1;
        return max(get(s,e,2*x,st,len),get(s,e,2*x+1,st+len,len));
    }
    void update(int s,int e,int v,int x,int st,int len){ // s-e | st-st+len-1
        push(x,len);
        if(e<st || st+len-1<s) return;
        if(s<=st && st+len-1<=e){
            lazy[x] += v;
            push(x,len);
            return;
        }
        len>>=1;
        update(s,e,v,2*x,st,len);
        update(s,e,v,2*x+1,st+len,len);
        mx[x]=max(mx[2*x+1],mx[2*x]);
    }
    int get(){
        return get(0,sz-1,1,0,sz);
    }
    void update(int s,int e,int v){update(s,e,v,1,0,sz);}
} S;
vector<int> b[MAXN],e[MAXN];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    for(int A,B,i=0;i<n;i++){
        cin>>A>>a[i].E>>B>>a[i].S;
        ys.push_back(a[i].S);
        ys.push_back(a[i].E);
    }
    sort(ys.begin(),ys.end());
    ys.erase(unique(ys.begin(),ys.end()),ys.end());
    for(int i=0;i<n;i++){
        int st,end;
        st = lower_bound(ys.begin(),ys.end(),a[i].S)-ys.begin();
        end = lower_bound(ys.begin(),ys.end(),a[i].E)-ys.begin();
        S.update(st,end,1);
        b[st].push_back(end);
        e[end].push_back(st);
    }
    int k=0;
    for(int i=0;i<ys.size();i++){
        for(int end:b[i])
            S.update(i,end,-1), k++;
        ans = max(ans, k+S.get());
        for(int st:e[i])
            S.update(st,i,1), k--;
    }
    cout<<ans;
}