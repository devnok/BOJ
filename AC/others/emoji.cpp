#include<iostream>
#include<vector>
using namespace std;

int k;
using pii = pair<int,int>;
vector<pii> ans;
void move(int a,int b,int h){
    if(h==1){
        ans.push_back({a,b});
        return;
    }
    move(a,6-a-b,h-1);
    ans.push_back({a,b});
    move(6-a-b,b,h-1);
}
int main(){
    cin>>k;
    move(1,3,k);
    cout<<ans.size();
    for(pii a:ans) cout<<"\n"<<a.first<<" "<<a.second;
}