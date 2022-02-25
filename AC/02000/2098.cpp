#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <bitset>
#include <functional>
#include <chrono>
#include <random>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
using namespace std;

using base = complex<double>;

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
using vb = vector<base>;

#define x first
#define y second
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define cpr(v) sort(all(v)); (v).erase(unique(all(v)), (v).end())
#define idx(v, x) int(lower_bound(all(v), (x)) - (v).begin())
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

const int MAX = 16;
const int INF = 1e9;
int n;
int m[MAX][MAX];
int dp[MAX][1<<MAX];
 
int tsp(int cur, int visit) {
    //방문한 곳은 재방문하지 않았으므로 다시 원점으로 돌아오는 가중치를 return해줘서 더해준다.
   if(visit == (1<<n)-1)
       return (m[cur][0]>0) ? m[cur][0] : INF;
   int &ret=dp[cur][visit];
   if(ret>0)   return ret;
   ret=INF;
   for(int i=0; i<n; i++) {
       if(!(visit & (1<<i)) && m[cur][i]>0) {
           ret=min(ret, tsp(i, visit|(1<<i)) + m[cur][i]);
       }
   }
   return ret;
}
 
int main() {
    cin>>n;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    cout<<tsp(0,1)<<endl;
    return 0;
}