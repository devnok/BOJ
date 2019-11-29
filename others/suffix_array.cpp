#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 500050;
string s;
int tmp[MAXN],sa[MAXN],lcp[MAXN],d=1,n,g[MAXN];
bool cmp(int i,int j){
    if(g[i]!=g[j]) return g[i]<g[j];
    i+=d, j+=d;
    return (i<n && j<n)?g[i]<g[j]:j<i;
}
void suffix_array(string s){
    n=s.size();
    for(int i=0;i<n;i++){
        sa[i]=i;
        g[i]=s[i];
    }
    for(d=1;;d*=2){
        sort(sa,sa+n,cmp);
        for(int i=1;i<n;i++)
            tmp[i]=tmp[i-1]+cmp(sa[i-1],sa[i]);
        for(int i=0;i<n;i++)
            g[sa[i]] = tmp[i];
        if(tmp[n-1]==n-1) return;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>s;
    suffix_array(s);
    int i,j,k;
    for(i=0,k=0;i<n;i++,k=max(k-1,0)){
        if(g[i]==n+1) continue;
        for(j=sa[g[i]+1];s[i+k]==s[j+k];k++);
        lcp[g[i]] = k;
    }
    for(i=0;i<n;i++) cout<<sa[i]+1<<" ";
    cout<<"\nx ";
    for(i=0;i<n-1;i++)
        cout<<lcp[i]<<" ";
}