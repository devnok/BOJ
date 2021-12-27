#include<iostream>
#include<queue>
#include<string>
using namespace std;

const int dy[4]={-1,0,1,0};
const int dx[4]={0,-1,0,1};
struct ST{
    int y, x, keys;
    ST(int _y,int _x,int _keys):y(_y),x(_x),keys(_keys){}
};
int v[64][101][101];
string s[101];
int n,m;
bool isKey(char c){return c>='a'&&c<='f'; }
bool needKey(char c){return c>='A'&&c<='F'; }
bool hasKey(char k,int keys){return (keys>>(k-'A'))&1; }
bool inRange(int y,int x){return y>=0&&x>=0&&y<n&&x<m; }
int main(){
    cin>>n>>m;
    queue<ST> q;
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<m;j++)
            if(s[i][j]=='0'){
                q.push(ST(i,j,0));
                v[0][i][j]=1;
            }
    }

    while(!q.empty()){
        ST here = q.front(); q.pop();
        int y=here.y,x=here.x,k=here.keys;
        if(s[y][x]=='1'){
            cout<<v[k][y][x]-1;
            return 0;
        }
        for(int i=0;i<4;i++){
            int Y = y+dy[i];
            int X = x+dx[i];
            if(!inRange(Y,X)) continue;
            char h=s[Y][X];
            if(h=='#'||(needKey(h)&&!hasKey(h,k))) continue;
            int nk = k;
            if(isKey(h)) nk |= 1<<(h-'a');
            if(!v[nk][Y][X]){
                q.push(ST(Y,X,nk));
                v[nk][Y][X]=v[k][y][x]+1;
            }
        }
    }
    puts("-1");
}