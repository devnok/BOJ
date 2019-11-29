#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Chain{
    int r,l,num;
    Chain(int r,int l,int num):r(r),l(l),num(num){}
};
bool cmp(Chain& a,Chain& b){return a.r==b.r?a.l<b.l:a.r<b.r;}
bool cmp2(Chain& a,Chain& b){return a.l==b.r?a.r<b.r:a.l<b.r;}
const int MAXN = 100010;
int r[MAXN],l[MAXN],rl[MAXN],lr[MAXN],n;
Chain a[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>a[i].r>>a[i].l;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        a[i].num=i;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        lr[i] = a[i].num;
        rl[a[i].num] = i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
        }
    }
}