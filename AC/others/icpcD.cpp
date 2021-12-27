#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 300030;
struct xy{
    int x,y;
};
xy a[MAXN];
bool cmp(const xy& a,const xy& b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int n;
int bs(int x){
    int s=x,e=n-1;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        bs(i);
    }
}