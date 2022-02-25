#include<iostream>
using namespace std;

using ll = long long;
int n;
const int k=1000000000;
ll dp[1001000];

int main(){
  cin>>n;
  dp[2]=1;
  for(int i=3;i<=n;i++) dp[i]=(i-1)*(dp[i-2]+dp[i-1])%k;
  cout<<dp[n];
}