#include<iostream>
#include<numeric>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int a[500050],n,num[10001],ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i],num[a[i]+4000]++;
    sort(a,a+n);

    double avg = accumulate(a,a+n,0)/double(n);
    if(avg > -0.5) avg = abs(avg);
    
    printf("%.0lf\n", avg);
    printf("%d\n", a[n/2]);
    for(int i=a[0]+4000;i<=a[n-1]+4000;i++){
        ans=max(num[i],ans);
    }
    vector<int> nums;
    for(int i=a[0]+4000;i<=a[n-1]+4000;i++){
        if(ans==num[i]){
            nums.push_back(i);
        }
    }
    sort(nums.begin(), nums.end());
    if(nums.size() == 1) cout<<nums[0]-4000<<endl;
    else cout<<nums[1]-4000<<endl;
    cout<<a[n-1]-a[0];
}