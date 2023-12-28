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

int st[7] = {100,50,20,10,5,2,1};

int main(void){
  cin.tie(0)->sync_with_stdio(0);
  
  int n,k=0;
  cin >> n;
  vint a(n);
  for(auto& i:a) cin>>i;

  for(int i=0;i<n;i++){
    if(k>0) k-=a[i];
    else k+=a[i];
  }
  k = k>0 ? k : -k;
  int cnt=0;
  while(k>0) {
    for(int s:st)
      if(s<=k){
        k-=s;
        break;
    }
    cnt++;
  }
  cout<<cnt;
}