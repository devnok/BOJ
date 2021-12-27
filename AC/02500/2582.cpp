#include<bits/stdc++.h>
using namespace std;

vector<string> b;
int n,i,j,c[35][35],ans=2000,ccnt[35];
double k=4.0,T=1.0;

int main(){
    mt19937 rd = mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());
    srand(4120129);
    cin>>n; b.resize(n);
    uniform_int_distribution<int> ran(0, n-1);
    for(auto& s:b) cin>>s;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            c[i][j] = b[i][j] == 'T';
            ccnt[j] += c[i][j];
        }
    }
    for(i=0;i<1010101;i++){
        int r = rand()%n,e1=0,e2=0;
        for(j=0;j<n;j++){
            e1 += min(ccnt[j],n-ccnt[j]);
            ccnt[j] += c[r][j]?-1:1;
            c[r][j]^=1;
            e2 += min(ccnt[j],n-ccnt[j]);
        }
        double P = exp((e1-e2)/k*T);
        if(P > ran(rd) / double(n-1)){
            for(j=0;j<n;j++){
                ccnt[j] += c[r][j]?-1:1;
                c[r][j]^=1;
            }
        }
        k*=0.9999;
        ans = min(ans,e1);
    }
    cout<<ans;
}