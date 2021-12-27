#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

const int MAXN = 200020;
int sa[MAXN],t,a[MAXN],ta[MAXN],n;
int lcp[MAXN],rk[MAXN];

string s;
bool cmp(int x,int y){
    if(a[x]==a[y]){
        if(x+t>=n) return y+t<n;
        return a[x+t] < a[y+t];
    }
    return a[x] < a[y];
}

void getSA(){
    t=1;
    for(int i=0;i<n;i++){
        sa[i]=i;
        a[i]=s[i]-'a';
    }
    while(t<=n){
        a[n]=-1;
        sort(sa,sa+n,cmp);
        ta[sa[0]]=0;
        for(int i=1;i<n;i++){
            ta[sa[i]] = ta[sa[i-1]] + cmp(sa[i-1],sa[i]);
        }
        for(int i=0;i<n;i++) a[i]=ta[i];
        t*=2;
    }
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    s=s1+"$"+s2;
    int n1 = s1.length(), n2 = s2.length();
    n = n1+n2+1;
    getSA();
    int i,j,k=0,r=0,rr=-1,cx;
    for(i=0;i<n;i++) rk[sa[i]]=i;
    for(i=0;i<n;lcp[rk[i++]]=k)
        for(k?k--:0,j=sa[rk[i]-1];s[i+k]==s[j+k]&&rk[i];k++);
    for(int i=1;i<n;i++){
        if(sa[i-1]<n1&&sa[i]>n1){
            cx = min(n1-sa[i-1],lcp[i]);
            if(cx>r) r=cx,rr=sa[i];
        } else if(sa[i-1]>n1&&sa[i]<n1){
            cx = min(n1-sa[i],lcp[i]);
            if(cx>r) r=cx,rr=sa[i];
        }
    }
    cout<<r<<endl;
    for(int i=0;i<r;i++) cout<<s[i+rr];
}
// rk[i] = i-n 접미사가 몇번째인가
/*
&aa 1 rk 2
a   3    0
a&aa0    3
aa  2    1
*/