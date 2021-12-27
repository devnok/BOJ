#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n;
    double num[10010],ans;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<=n;i++){
        double sum=1;
        for(int j=i;j<=n;j++){
            sum *= num[j];
            ans = max(ans, sum);
        }
    }
    cout<<fixed<<setprecision(3)<<ans;
}