#include<iostream>
#include<vector>
#include<string.h>
#include<set>
using namespace std;

int a[101][101],n,m,cnt[101];
int sortRow(int y){
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<m;i++) cnt[a[y][i]]++,a[y][i]=0;
    set<int> b[101];
    for(int j=1;j<=100;j++) b[cnt[j]].insert(j);
    int k=0;
    for(int j=1;j<=100;j++){
        for(auto it=b[j].begin();it!=b[j].end();it++){
            int num = *it;
            a[y][k]=num;
            a[y][k+1]=j;
            k+=2;
        }
    }
    return k;
}
int sortCol(int x){
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<m;i++) cnt[a[i][x]]++,a[i][x]=0;
    set<int> b[101];
    for(int j=1;j<=100;j++) b[cnt[j]].insert(j);
    int k=0;
    for(int j=1;j<=100;j++){
        for(auto it=b[j].begin();it!=b[j].end();it++){
            int num = *it;
            a[k][x]=num;
            a[k+1][x]=j;
            k+=2;
        }
    }
    return k;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int t,r,c,k;
    cin>>r>>c>>k;
    r--;c--;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>a[i][j];
    n=m=3;
    for(t=0;a[r][c]!=k;t++){
        int N=n,M=m;
        if(t>=100){
            puts("-1");
            return 0;
        }
        if(n>=m){
            M=0;
            for(int i=0;i<n;i++) M=max(M,sortRow(i));
        } else {
            N=0;
            for(int i=0;i<m;i++) N=max(N,sortCol(i));
        }
        n=N,m=M;
    }
    cout<<t;
}