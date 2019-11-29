#include<iostream>
#include<set>
#include<string>
using namespace std;

#define MAXN 1000100
#define INF 987654321
int a[MAXN],n,k,ans=INF;
multiset<int> ms;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n-k;i++){
        ms.insert(a[i]-a[i-1]);
    }
    for(int i=0;i<k+1;i++){
        int M=a[i+n-k-1]-a[i];
        int m=*ms.begin();
        cout<<M<<" "<<m<<endl;
        ans=min(ans,M+m);
        ms.erase(ms.find(a[i+1]-a[i]));
        if(i!=k) ms.insert(a[n-k+i]-a[n-k+i-1]);
    }
    cout<<ans;
}