#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<string>
using namespace std;
#define X first
#define Y second

const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int n,v[51][51][101];
string m[51];

bool inRange(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n;
}

piii make_piii(int d,int x,int y){
    return make_pair(d,make_pair(x,y));
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    priority_queue<piii> pq;
    pq.push(make_piii(-1,0,0));
    while(!pq.empty()){
        pii xy=pq.top().second;
        int x=xy.X,y=xy.Y;
        int d=-pq.top().first; pq.pop();
        if(x==n-1&&y==n-1){
            cout<<d-1;
            break;
        }
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(!inRange(xx,yy)) continue;
            int dd=d+1-(m[xx][yy]-'0');
            if(v[xx][yy][dd]) continue;
            v[xx][yy][dd]=1;
            pq.push(make_piii(-dd,xx,yy));
        }
    }

}