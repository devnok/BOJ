
#include <vector>
using namespace std;

int dp[1005];

int main(){
    //freopen("input.txt","r",stdin);
    vector<int> v,a;
    vector<int>::iterator iter;
    int n,p;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        iter = lower_bound(v.begin(),v.end(),x);
        if(iter!=v.end()) *iter = x;
        else v.push_back(x);

        iter = lower_bound(v.begin(),v.end(),x);
        p = iter - v.begin();
        dp[x] = p?v[p-1]:0;
    }
    for(int i=v.back();i;i=dp[i])
        a.push_back(i);

    printf("%d\n",a.size());
    for(int i=(int)a.size()-1;i>=0;i--)
        printf("%d ",a[i]);

    return 0;
}
