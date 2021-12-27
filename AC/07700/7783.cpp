#include<iostream>
#include<vector>
#include<string>
using namespace std;

int mx[4][202],m,n,a[4][202][202],b[4][202][202],ans=-1;
int fence(int c,int y,int x,int lim){ // | => x
    int st[202],fences[202], TOP = -1,ret=-1;
    for(int i=x;i<lim;i++) fences[i-x] = b[c][y][i];
    fences[lim-x]=0;
    for(int i=0;i<=lim-x;i++){
        while(TOP>=0&&fences[st[TOP]] >= fences[i]){
            int j = st[TOP--];
            int width = (TOP<0 ? i : i-st[TOP]-1);
            ret = max(ret, width * fences[j]);
        }
        st[++TOP] = i;
    }
    return ret;
}
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) scanf("%1d",&a[0][i][j]);
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) a[1][i][n-1-j]=a[2][j][m-1-i] = a[0][i][j];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) a[3][i][m-1-j] = a[2][i][j];
    for(int c=0;c<4;c++){
        int lim = c<2 ? m : n;
        for(int j=0;j<n+m-lim;j++) b[c][0][j] = !a[c][0][j];
        for(int i=1;i<lim;i++) for(int j=0;j<n+m-lim;j++) b[c][i][j] = !a[c][i][j] * (b[c][i-1][j]+1) ;
    }
    for(int c=0;c<4;c++){
        int N = (c<2 ? n : m);
        int M = n+m-N;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                mx[c][i] = max(mx[c][i],fence(c,j,i,N));
            }
        }
    }
    for(int i=1;i<n-1;i++) ans = max(ans, mx[0][i]+mx[1][n-i]);
    for(int i=1;i<m-1;i++) ans = max(ans, mx[2][i]+mx[3][m-i]);
    cout<<ans;
}
