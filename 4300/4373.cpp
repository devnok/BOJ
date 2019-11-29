#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct vxy{
    int v,x,y;
    vxy(int _v,int _x,int _y):v(_v),x(_x),y(_y){}
};
bool operator<(vxy x,vxy y){return x.v < y.v;}
int main(){
    while(true){
        int n; cin>>n;
        if(!n) break;
        bool solved = false;
        vector<int> arr(n);
        vector<vxy> sums;
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(i!=j) sums.push_back(vxy(arr[i]+arr[j],arr[i],arr[j]));
            }
        } sort(sums.begin(),sums.end());
        for(int i=n-1;i>=0;i--){
            int c,d=arr[i];
            for(int j=0;j<n;j++){
                c=arr[j];
                if(i==j) continue;
                int s = lower_bound(sums.begin(),sums.end(),vxy(d-c,0,0)) - sums.begin();
                int e = upper_bound(sums.begin(),sums.end(),vxy(d-c,0,0)) - sums.begin();
                for(int k=s;k<=e;k++){
                    if(sums[k].v+c==d){
                        if(sums[k].x!=c&&sums[k].y!=c&&sums[k].x!=d&&sums[k].y!=d){
                            cout<<d<<endl;
                            solved = true;
                            break;
                        }
                    }
                }
                if(solved) break;
            }
            if(solved) break;
        }
        if(!solved) puts("no solution");
    }
}