#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

int H,W,S[2]; // S[0] : 2*2, S[1] : 1*3
int board[20][20],dp[20][1<<18];
string s[20];
void printBoard(){
    cout<<"\n--------\n";
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<"--------\n";
}
bool inMap(int x,int y){
    return x>=0&&y>=0&&x<W&&y<H;
}
bool canCover(int x,int y,int type){
    if(type==0){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                int X = x+i,Y=y+j;
                if(!inMap(X,Y) || board[X][Y]) return false;
            }
        }
    }
    if(type==1){
        for(int i=0;i<3;i++){
            if(!inMap(x,y+i) || board[x][y+i]) return false;
        }
    }
    return true;
}
bool cover(int x,int y,int type,int t){
    if(t==1 && !canCover(x,y,type)) return false;
    if(type==0){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                board[x+i][y+j] += t;
            }
        }
    }
    if(type==1){
        for(int i=0;i<3;i++){
            board[x][y+i] += t;
        }
    }
    return true;
}
int set(int x,int covered){
    if(x==W) return 0;
    int y;
    int& ret = dp[x][covered];
    if(ret != -1) return ret;
    ret=0;
    for(y=0;y<H;y++){
        if(board[x][y]) continue;
        for(int i=0;i<2;i++){
            if(cover(x,y,i,1)){
                for(int j=0;j<2+i;j++){
                    covered |= (1 << (y+j));
                }
                ret = max(ret, S[i]+set(x,covered));
                for(int j=0;j<2+i;j++){
                    covered &= ~(1 << (y+j));
                }
                cover(x,y,i,-1);
            }
        }
    }
    int cov=0;
    for(int i=0;i<H;i++) cov += (board[x+1][i] << i);
    ret = max(ret,set(x+1,cov));
    printBoard();
    cout<<x<<endl;
    cout<<ret<<endl;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>H>>W>>S[0]>>S[1];
    for(int i=0;i<H;i++){
        cin>>s[i];
        for(int j=0;j<W;j++){
            board[j][i] = (s[i][j] == 'X') ? 1 : 0; // 90도 돌려진 상태
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    int c=0;
    for(int i=0;i<H;i++) c += (board[0][i] << i);
    cout<<set(0,c);
}