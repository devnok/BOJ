#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define X first
#define R second

const int MAXN = 300030;
const int sz = 1 << 19;
typedef pair<int,int> pii;
typedef long long int lld;
struct Line{
    int x,y,z;
    Line(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
};
struct Seg{
    int dat[sz*2];
    void update(int x,int v){dat[x+=sz]+=v; for(x/=2;x;x/=2) dat[x]+=v; }
    int get(int s,int e){
        int r=0;
        for(s+=sz,e+=sz;s<=e;s/=2,e/=2){
            if(s%2==1) r+=dat[s++];
            if(e%2==0) r+=dat[e--];
        }
        return r;
    }
} S;
bool operator<(const Line x,const Line y){return (x.x==y.x)?x.y>y.y : x.x<y.x;}
pii c[MAXN];
vector<Line> lines;
int n,ans,r[MAXN],lim=20;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>c[i].X>>c[i].R;

    for(int i=0;i<n;i++){
        int x=c[i].X,r=c[i].R;
        lines.push_back(Line(x-r,r,1));
        lines.push_back(Line(x+r,r,-1));
    }
    sort(lines.begin(),lines.end());
    for(Line line : lines){
        cout<<ans<<endl;
        ans+=S.get(0,line.y+lim);
        S.update(line.y+lim,line.z);
    }
    cout<<ans;
}