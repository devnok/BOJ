#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<string.h>
using namespace std;
#define mp make_pair
typedef pair<int,int> pii;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
struct xy{
    int x,y,kn;
    xy(int x1,int y1,int kn1):x(x1),y(y1),kn(kn1){}
};
bool operator<(const xy& a,const xy& b){return a.kn < b.kn;}
int T,H,W;
int k[110][110],v[110][110];
int s2i(string s){
    if(s=="0") return 0;
    int r = 0;
    for(auto c:s){
        r += 1 << (c-'a');
    }
    return r;
}
vector<string> m;
bool inRange(int x,int y){return x>=0&&y>=0&&x<H&&y<W;}
bool isDoor(char c){return c<='Z' && c>='A';}
bool isKey(char c){return c<='z' && c>='a';}
int keyN(int keys){
    int r=0;
    for(int i=0;i<26;i++){
        if((keys>>i)&1) r++;
    }
    return r;
}
bool hasKey(int x,int y,char c){
    c=c-'A';
    return (k[x][y] >> c) & 1;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>T;
    while(T--){
        cin>>H>>W;
        m.resize(H+2);
        memset(k,0,sizeof(k));
        memset(v,-1,sizeof(v));
        for(int i=1;i<=H;i++){
            cin>>m[i];
            m[i] = "."+m[i]+".";
            for(int j=1;j<=W;j++){
                if(isKey(m[i][j])) k[i][j] = (1<<(m[i][j]-'a'));
            }
        }
        H+=2; W+=2;
        m[0]=string(W,'.');
        m[H-1]=string(W,'.');
        priority_queue<xy> pq;
        string s; cin>>s;
        k[0][0] = s2i(s);
        v[0][0] = k[0][0] ? s.length() : 0;
        pq.push(xy(0,0,v[0][0]));
        while(!pq.empty()){
            int x = pq.top().x;
            int y = pq.top().y;
            int kn = pq.top().kn; pq.pop();
            if(v[x][y] > kn) continue;
            for(int i=0;i<4;i++){
                int X = x+dx[i], Y = y+dy[i];
                if(!inRange(X,Y) || m[X][Y] == '*') continue;
                if(isDoor(m[X][Y]) && !hasKey(x,y,m[X][Y])) continue;
                int K = k[x][y] | k[X][Y];
                int KN = keyN(K);
                if(v[X][Y] < KN){
                    v[X][Y] = KN;
                    k[X][Y] = K;
                    pq.push(xy(X,Y,KN));
                }
            }
        }
        queue<pii> q;
        q.push(mp(0,0));
        memset(v,0,sizeof(v));
        int ans=0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second; q.pop();
            for(int i=0;i<4;i++){
                int X = x+dx[i], Y = y+dy[i];
                if(!inRange(X,Y) || m[X][Y] == '*') continue;
                if(isDoor(m[X][Y]) && !hasKey(x,y,m[X][Y])) continue;
                if(!v[X][Y]){
                    if(m[X][Y] == '$') ans++;
                    q.push(mp(X,Y));
                    v[X][Y]=1;
                }
            }
        }
        cout<<ans<<endl;
    }
}
/*
...................
.*****************.
..............**$*.
.*B*A*P*C**X*Y*.X..
.*y*x*a*p**$*$**$*.
.*****************.
*/