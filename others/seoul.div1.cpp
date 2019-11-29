#include<iostream>
#include<set>
#include<string>
using namespace std;

const int INF = 987654321;
multiset<int> a[26];
int n,ans=INF;
string s[100010];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n;
    for(int i=0;i<26;i++) a[i].insert(INF);
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<s[i].size();j++){
            a[s[i][j]-'a'].insert(j);
        }
    }
    for(string st:s){
        for(int j=0;j<st.size();j++){
            a[st[j]-'a'].erase(j);
        }
        for(int j=0;j<st.size();j++){
            int k = *a[st[j]-'a'].begin()+st.size()-j-1;
            cout<<st<<" "<<st[j]<<" -> "<<k<<endl;
            if(k) ans = min(ans,k);
        }
        for(int j=0;j<st.size();j++){
            a[st[j]-'a'].insert(j);
        }
    }
    if(ans>=INF) puts("-1");
    else cout<<ans;
}