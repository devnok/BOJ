#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>
#include<map>
#include<functional>
using namespace std;

using pii = pair<int,int>;
using piii = pair<int,pair<int,int>>;
using ti3 = tuple<int,int,int>;
const int MAXN = 200020;
piii q[MAXN];
ti3 tmp[MAXN];
int m,n,X[MAXN],Y[MAXN],x[MAXN],y[MAXN],dp[MAXN],M[MAXN];
const int sz = 1 << 18;
struct Seg{
    vector<int> dat;
    int lim;
    Seg(){dat.resize(sz*2,0);}
    Seg(int _n){
        for(lim=1;lim<_n;lim*=2);
        dat.resize(lim*2,0);
    }
    void update(int x,int v){dat[x+=lim]+=v; for(x/=2;x;x/=2) dat[x]=max(dat[2*x],dat[2*x+1]);}
    int get(int s,int e){
        int r=0;
        for(s+=lim,e+=lim;s<=e;s/=2,e/=2){
            if(s%2) r=max(r,dat[s++]);
            if(e%2==0) r=max(r,dat[e--]);
        }
        return r;
    }
};
void solve(int s,int e){
    //printf("%d %d / %d\n",s,e,*max_element(dp,dp+n));
    if(e-s<=10){
        for(int i=s;i<=e;i++){
            int mx=0;
            for(int j=s;j<i;j++){
                if(X[j]<X[i]&&Y[j]<Y[i]) mx=max(mx,dp[j]);
            }
            dp[i] = max(dp[i],mx+1);
        }
        return;
    }
    int mid = (s+e)/2,len = e-s+1;
    solve(s,mid);
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=s;i<=e;i++)
        pq.push(Y[i]);
    map<int,int> M;
    for(int i=s;i<=e;i++){
        M[pq.top()] = i-s;
        pq.pop();
    }
    for(int i=s;i<=e;i++){
        tmp[i-s] = make_tuple(X[i],M[Y[i]],i);
    }
    sort(tmp,tmp+len);
    Seg S(len+1);
    int a,b,idx;
    for(int i=s;i<=e;i++){
        tie(a,b,idx) = tmp[i-s];
        if(mid<idx)
            dp[idx] = max(dp[idx],S.get(0,b-1)+1);
        else
            S.update(b,dp[idx]);
    }
    solve(mid+1,e);
    //printf("%d %d / %d\n",s,e,*max_element(dp,dp+n));
}
pii v[MAXN];
vector<int> a;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>m>>n;
    if(m==2){
        for(int i=0;i<n;i++) cin>>v[i].first;
        for(int i=0;i<n;i++) cin>>v[i].second;
        sort(v,v+n);
        a.push_back(-987654321);
        for(int i=0;i<n;i++){
            int num = v[i].second;
            if(a.back()<num)
                a.push_back(num);
            else
                *lower_bound(a.begin(),a.end(),num) = num;
        }
        cout<<a.size()-1;
        return 0;
    }
    for(int i=0;i<n;i++) cin>>q[i].first;
    for(int i=0;i<n;i++) cin>>x[i], q[i].second.first=x[i]; 
    for(int i=0;i<n;i++) cin>>y[i], q[i].second.second=y[i];
    sort(q,q+n);
    //sort(x,x+n);
    //sort(y,y+n);
    for(int i=0;i<n;i++){
        tie(X[i],Y[i]) = q[i].second;
        //X[i] = lower_bound(x,x+n,q[i].second.first)-x;
        //Y[i] = lower_bound(y,y+n,q[i].second.second)-y;
    }
    solve(0,n-1);
    cout<<*max_element(dp,dp+n);
}