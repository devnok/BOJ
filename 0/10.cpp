#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int n,m,ans[220],a[101],b[21][101];
int eval(){
    int ret=0;
    for(int i=0;i<n;i++){
        if(a[i]) ret++;
        else ret--;
    }
    return ret;
}
void dfs(int t,int l){
    printf("%d %d %d\n",t,l,eval());
    ans[eval()+n] = t;
    if(l==m) return;
    dfs(t,l+1);
    for(int i=0;i<n;i++)
        a[i]^=b[l][i];
    dfs(t+(1<<l),l+1);
    for(int i=0;i<n;i++)
        a[i]^=b[l][i];
}
int countBits(int x){
    int ret=0;
    for(int i=0;i<m;i++)
        if((x>>i)&1) ret++;
    return ret;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        scanf("%1d",&a[i]);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%1d",&b[i][j]);
    int v = eval();
    dfs(0,0);
    for(int i=-n;i<=n;i++){
        if(i == v){
            puts("0");
        } else if(ans[i+n]){
            cout<<countBits(ans[i+n])<<" ";
            for(int j=0;j<m;j++){
                if((ans[i+n]>>j)&1){
                    cout<<j+1<<" ";
                }
            }
            cout<<endl;
        } else puts("-1");
    }
}