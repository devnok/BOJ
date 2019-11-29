#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int n,k,a[10][10],s[3][20],ans;
void rds(){
    int w[3],cnt[3],nongame=2;
    for(int i=0;i<3;i++) w[i]=cnt[i]=0;
    while(1){
        if(w[0] >= k){
            ans=1;return;
        }
        if(w[1] >= k || w[2] >= k) return;
        if(cnt[0]>=n) return;
        int mw,A,B;
        switch(nongame){
            case 0:
                A=1;B=2;break;
            case 1:
                A=0;B=2;break;
            case 2:
                A=0;B=1;break;
        }
        mw = a[s[A][cnt[A]]][s[B][cnt[B]]] == 2;
        cnt[A]++; cnt[B]++;
        mw ? w[A]++ : w[B]++;
        nongame = mw?B:A;
    }
}
void dfs(int x,int chk){
    if(x==n){
        rds();
        return;
    }
    for(int i=1;i<=n;i++){
        if((chk>>i)&1) continue;
        s[0][x]=i;
        dfs(x+1,(chk|(1<<i)));
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<3;i++){
        for(int j=0;j<20;j++){ cin>>s[i][j]; }
    }
    dfs(0,0);
    cout<<ans;
}