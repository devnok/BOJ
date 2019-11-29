#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<stdio.h>
using namespace std;

typedef long long ll;
int n,k;
const int MAX_N = 5010;
ll dp[MAX_N][MAX_N];
vector<int> a;
vector<int> ch[MAX_N];

ll group(int start, int groups){
    if(groups<=0)
        return 0;
    ll& ret = dp[start][groups];
    if(ret!=-1)
        return ret;
    int res=0;
    for(int i=0;i<ch[start].size();i++){
        int gEnd = ch[start][i];
        res |= a[gEnd];
        ret = max(ret, 1LL*res+group(gEnd+1,groups-1));
    }
    return ret;
}
int main(){
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        int res = 0;
        for(int j=i;j<n;j++){
            if((res|a[j]) != res){
                res |= a[j];
                ch[i].push_back(j);
            }
        }
    }
    cout<<group(0,k);
}
