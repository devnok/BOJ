#include<iostream>
#include<string>
using namespace std;

string s;
int n,ans;
int main(){
    cin>>n>>s;
    s+='A';
    for(int i=0;i<n;i++){
        if(s[i]!=s[i+1]){
            ans++;
            if(i&&s[i-1]==s[i+1]) s[i]=s[i+1], ans--;
        }
    }
    cout<<ans;
}
// AABABBAAABBAAA
// AAAABBAAABBAAA
// BBBBBBAAABBAAA
// AAAAAAAAABBAAA
// BBBBBBBBBBBAAA
// AAAAAAAAAAAAAA

// BBABABA
// BBBBABA
// AAAAABA
// AAAAAAA