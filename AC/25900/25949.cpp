#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int dp[30][105][105][105];

int solve(int k,int a,int b,int c){
    int& ret = dp[k][a][b][c];
    if(~ret) return ret;
    if(!a&&!b&&!c) return ret=0;

    if(a) ret = max(ret, a+b+c-solve(k+1,max(0,a-k),b,c));
    if(b) ret = max(ret, a+b+c-solve(k+1,a,max(0,b-k),c));
    if(c) ret = max(ret, a+b+c-solve(k+1,a,b,max(0,c-k)));

    return ret;
}

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  memset(dp, -1, sizeof(dp));
  ints(A,B,C);
  int s = A+B+C - solve(1,A,B,C)*2;
  puts(s>0 ? "S" : s<0 ? "F" : "D");
}