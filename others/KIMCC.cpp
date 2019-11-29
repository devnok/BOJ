#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> W[10010],R[10010];
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for(auto w:words){
        W[w.size()].push_back(w);
        reverse(w.begin(),w.end());
        R[w.size()].push_back(w);
    }
    for(int i=1;i<=10000;i++){
        sort(W[i].begin(),W[i].end());
        sort(R[i].begin(),R[i].end());
    }
    for(auto q:queries){
        int l = q.size();
        if(q[0]!='?'){
            int s = lower_bound(W[l].begin(),W[l].end(),q)-W[l].begin();
            for(auto& c:q) if(c=='?') c='z';
            int e = lower_bound(W[l].begin(),W[l].end(),q)-W[l].begin();
            answer.push_back(e-s);
        } else {
            reverse(q.begin(),q.end());
            for(auto w:R[l]){
                cout<<w<<endl;
            }
            int s = lower_bound(R[l].begin(),R[l].end(),q)-R[l].begin();
            for(auto& c:q) if(c=='?') c='z';
            int e = lower_bound(R[l].begin(),R[l].end(),q)-R[l].begin();
            cout<<q<<" "<<s<<" "<<e<<endl;
            answer.push_back(e-s);
        }
    }
    return answer;
}
int main(){
    int n;
    cin>>n;
    vector<string> words(n),queries(n);
    for(int i=0;i<n;i++) cin>>words[i];
    for(int i=0;i<n;i++) cin>>queries[i];
    vector<int> v = solution(words,queries);
    for(int i:v) cout<<i<<" ";
}