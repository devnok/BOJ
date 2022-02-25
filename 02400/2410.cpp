#include<iostream>
#include<algorithm>
using namespace std;
#define x first
#define y second

const int MAXN = 500005;
pair<int,int> a[MAXN];
int n, cow[MAXN], idx[MAXN*2];
long long ans, kans;

struct BIT{
    int dat[MAXN];
    void update(int x){for(;x<=n;x+=x&-x) dat[x]++;}
    int get(int x){int r=0;for(;x;x-=x&-x) r+=dat[x]; return r;}
    int get(int s,int e){return get(e)-get(s-1);}
} B;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cow[i];
        idx[cow[i]]=i+1;
    }
    for(int i=0;i<n;i++){
        cin>>cow[i];
        a[i].x = idx[cow[i]];
        a[i].y = i+1;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        kans += B.get(a[i].y+1,n);
        B.update(a[i].y);
    }
    ans = kans;
    for(int k=0;k<n;k++){
        kans += n-2*idx[cow[k]]+1;
        ans = min(ans, kans);
    }
    for(int k=0;k<n;k++){
        kans += n-2*a[k].y+1;
        ans = min(ans, kans);
    }
    cout<<ans;
}
