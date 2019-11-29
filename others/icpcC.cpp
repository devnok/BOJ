#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll n, w, s[16], total=0;
vector<int> indec;

int main() {
    cin>>n>>w;
    for(int i=1;i<=n;i++) cin>>s[i];
    int nowState = 0, isFound = 0; // 1 UP -1 DOWN

    for(int i=2;i<=n;i++) {
        if(s[i]<s[i-1] && nowState==1) {
            if(isFound) indec.push_back(i-1);
            nowState=-1;
            isFound = 1;
        }
        else if(s[i]>s[i-1] && (nowState==-1 || !isFound)) {
            indec.push_back(i-1);
            nowState=1;
            isFound = 1;
        }
    }
    if(nowState == 1) indec.push_back(n);

    ll sw=0,coin=0;
    for(auto idx:indec) {
        if(sw) {
            w+=coin*s[idx];
            coin = 0;
            sw=!sw;
            //cout << "Sell> coin: " << coin << " w: " << w << endl;
        }
        else {
            coin = coin + ((w/s[idx]));
            w = w - (w/s[idx]*s[idx]);
            sw=!sw;
            //cout << "Buy> coin: " << coin << " w: " << w << endl;
        }
    }
    cout << w;

    return 0;
}