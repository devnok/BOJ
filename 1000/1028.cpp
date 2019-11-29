#include<iostream>
#include<string.h>
using namespace std;

const int dy[4] = {-1,1,1,-1};
const int dx[4] = {1,1,-1,-1};
const int M = 770;
int r,c,sz,i,j,m[4][M][M];
int cave[M][M];

inline bool inMap(int y,int x){
    return y>=0&&x>=0&&y<r&&x<c;
}
int len(int y,int x,int d){
    if(!inMap(y,x) || !cave[y][x]) return 0;
    int& ret = m[d][y][x];
    if(~ret) return ret;
    return ret = 1 + len(y+dy[d],x+dx[d],d);
}
bool find(int y,int x,int m){
    int ys[4] = {y,y-m,y,y+m};
    int xs[4] = {x-m,x,x+m,x};
    for(int i=0;i<4;i++)
        if(len(ys[i],xs[i],i)<=m) return 0;
    return 1;
}
int main(){
    memset(m,-1,sizeof(m));
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%1d",&cave[i][j]);
    for(sz=min(r-1,c-1)/2;sz>=0;sz--){
        for(i=sz;i<r-sz;i++)
            for(j=sz;j<c-sz;j++)
                if(find(i,j,sz)){
                    printf("%d",sz+1);
                    return 0;
                }
    }
    puts("0");
}