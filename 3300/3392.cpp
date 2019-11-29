#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

typedef pair<int,int> pii;
typedef long long int lld;
const int lim = 1<<16;

struct Seg{
    int dat[lim*2],cnt[lim*2];
    void update(int s,int e,int v){update(s,e,v,1,0,lim);}
    void update(int s,int e,int v,int x,int st,int len){
        int end = st+len-1;
        if(end<s||st>e) return;
        if(s<=st&&end<=e)
            cnt[x]+=v;
        else{
            int l = len>>1;
            update(s,e,v,2*x,st,l);
            update(s,e,v,2*x+1,st+l,l);
        }
        if(cnt[x]) dat[x]=len;
        else
            dat[x]=len>1?dat[2*x+1]+dat[2*x]:0;
        //printf("%d %d %d %d %d %d %d(%d,%d)\n",s,e,v,x,st,len,dat[x],dat[2*x],dat[2*x+1]);
    }
} S;
struct Line{
    int x,y1,y2,l;
    Line(int _x,int _y1,int _y2,int _l):x(_x),y1(_y1),y2(_y2),l(_l){}
};
bool cmp(const Line x,const Line y){return x.x < y.x;}
vector<Line> lines;
int n;
long long int ans;
int main(){
    cin>>n;
    for(int x1,y1,x2,y2,i=0;i<n;i++){
        cin>>x1>>y1>>x2>>y2;
        lines.push_back(Line(x1,y1,y2,1));
        lines.push_back(Line(x2,y1,y2,-1));
    }
    sort(lines.begin(),lines.end(),cmp);
    S.update(lines[0].y1,lines[0].y2-1,1);
    for(int i=1;i<lines.size();i++){
        Line line = lines[i];
        ans+=S.dat[1]*(line.x-lines[i-1].x);
        printf("%d : %d, %d * %d\n",i,line.x,S.dat[1],(line.x-lines[i-1].x));
        S.update(line.y1,line.y2-1,line.l);
    }
    cout<<ans;
}