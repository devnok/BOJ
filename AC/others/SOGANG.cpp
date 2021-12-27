#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
struct crop{
    int x,y,w;
    double d(){return pow(x*x+y*y,0.5);}
} v[MAXN];
bool cmp(crop&a,crop& b){return a.d()<b.d();}
int a,n,i,pw[MAXN];
double p[MAXN],ans=0;
int main(){
    cin>>n>>a;
    for(i=1;i<=n;i++) cin>>v[i].x>>v[i].y>>v[i].w;
    double s=0,e=2000;
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;i++) pw[i]=pw[i-1]+v[i].w,p[i]=p[i-1]+v[i].d()*v[i].w;
    for(i=1;i<=n;i++){
        double vr = pw[i]/(double)(a*2);
        double r=v[i].d();
        if(r<vr){
            r=vr;
            if(i<n) r=min(r,v[i+1].d());
        }
        double c = r*pw[i]-p[i];
        ans = max(ans,c-r*r*a);
        cout<<c<<" "<<r<<" "<<r*r*a<<endl;
    }
    printf("%.7lf",ans);
}
/**
r*pw[i]-p[i]-r*r*a

-a pw[i] -p[i]

pw[i]/a
*/