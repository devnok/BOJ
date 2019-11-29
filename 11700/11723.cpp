#include<iostream>
#include<vector>
#include<string>
using namespace std;
int bit,m,x;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>m;
    while(m--){
        string s; cin>>s;
        if(s=="add"){
            cin>>x;
            bit |= (1<<x);
        } else if(s=="remove"){
            cin>>x;
            bit &= ~(1<<x);
        } else if(s=="check"){
            cin>>x;
            cout<<(bit>>x&1)<<"\n";
        } else if(s=="toggle"){
            cin>>x;
            bit ^= (1<<x);
        } else if(s=="all"){
            bit = (1<<21)-1;
        } else if(s=="empty"){
            bit = 0;
        }
    }
}