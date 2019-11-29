#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

int dp[101][101][101];
string p,s[101];
int N;
bool match(int k,int i,int j){
    int& ret = dp[k][i][j];
    if(ret != -1) return ret;
    if(p.length() <= i)
        return ret = (s[k].length() <= j);
    if(p[i]=='*'){
        if(s[k].length() <= j)
            return match(k,i+1,j);
        return ret = (match(k,i,j+1) || match(k,i+1,j));
    }
    return ret = (p[i]==s[k][j]?match(k,i+1,j+1):0);
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>p>>N;
    for(int i=0;i<N;i++){
        cin>>s[i];
        memset(dp[i],-1,sizeof(dp[i]));
        if(match(i,0,0)) cout<<s[i]<<endl;
    }
}