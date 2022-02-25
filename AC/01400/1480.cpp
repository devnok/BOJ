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

int n, m, c,a[13],dp[1<<13],r;
int main() {
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 1; i < 1 << n; i++) {
		int s = 0,t=0;
		for (int j = 0; j < n; j++) if (1 << j&i) s += a[j],t++;
		dp[i] = s > c ? 1e9 : 1;
		for (int j = 1; j < i; j++) if ((i | j) == i && dp[j] + dp[i^j] < dp[i]) dp[i] = dp[j] + dp[i^j];
		if (dp[i] <= m && t > r) r = t;
	}
	printf("%d", r);
	return 0;
}