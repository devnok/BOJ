#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

const int MAXN = 1500020;
int sa[MAXN],t,a[MAXN],ta[MAXN],n;
int lcp[MAXN],rk[MAXN];

string s;
bool cmp(int x,int y){
    if(a[x]==a[y]){
        if(x+t>=n) return y+t<n;
        return a[x+t] < a[y+t];
    }
    return a[x] < a[y];
}

void getSA(){
    t=1;
    for(int i=0;i<n;i++){
        sa[i]=i;
        a[i]=s[i]-'a';
    }
    while(t<=n){
        a[n]=-1;
        sort(sa,sa+n,cmp);
        ta[sa[0]]=0;
        for(int i=1;i<n;i++){
            ta[sa[i]] = ta[sa[i-1]] + cmp(sa[i-1],sa[i]);
        }
        for(int i=0;i<n;i++) a[i]=ta[i];
        t*=2;
    }
}
#define mp make_pair
typedef pair<int,int> pii;
vector<pii> term[101];
int pn[101],ps[101];
string p[101],S;
int main(){
    int N; cin>>N;
    for(int i=0;i<N;i++){
        cin>>ps[i]>>p[i];
    }
    cin>>n>>S;
    s=S;
    for(int i=0;i<N;i++){
        pn[i] = s.size();
        s=s+"$"+p[i];
    }
    cout<<s<<endl;
    n = s.size();
    getSA();
    int i,j,k=0,r=0,rr=-1,cx;
    for(i=0;i<n;i++) rk[sa[i]]=i;
    for(i=0;i<n;lcp[rk[i++]]=k)
        for(k?k--:0,j=sa[rk[i]-1];s[i+k]==s[j+k]&&max(i,j)+k<n&&rk[i];k++);
    for(i=0;i<N;i++){
        cout<<"---"<<p[i]<<endl;
        for(j=rk[pn[i]];lcp[j]>=p[i].size();j++){
            cout<<s.substr(j)<<endl;
            if(sa[j]<S.size()){
                term[i].push_back(mp(sa[j],sa[j]+ps[i]));
                cout<<term[i].back().first<<endl;;
            }
        }
    }
    int ans=987654321;
    for(int i=0;i<S.size();i++){
        int st=987654321,e=0;
        for(int j=0;j<N;j++){
            pii c = *lower_bound(term[j].begin(),term[j].end(),mp(i,0));
            st = min(st,c.first);
            e = max(e,c.second);
        }
        ans = min(ans,e-st+1);
    }
    cout<<ans;
}