#include<string>
#include<iostream>

using namespace std;
 
int n;
string s;
int main() {
  cin >> n >> s;
  int ans = 0;
  bool turn = false;
  for (int i = n - 1; i >= 0; --i) {
    cout<<i<<endl;
    if (!turn && s[i] == 'B') {
      ++ans;
      if (i > 0 && s[i] == s[i-1]) {
        turn ^= 1;
        while (i > 0 && s[i] == s[i-1]) {
          --i;
        }
      }
    } else if (turn && s[i] == 'A') {
      ++ans;
      if (i > 0 && s[i] == s[i-1]) {
        turn ^= 1;
        while (i > 0 && s[i] == s[i-1]) {
          --i;
        }
      }
    }
  }
  cout << ans ;
}