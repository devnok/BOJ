#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
using namespace std;
typedef long long ll;
vector<ll> ans;
int arr[10]={0,1,2,3,4,5,6,7,8,9};
 
void func(int N,ll sum){
    if(N==-1){
        ans.push_back(sum);
        return ;
    }    
    func(N-1,sum);
    func(N-1,sum*10+N);
}
 
int main()
{
    func(9,0);
    for(int N=0;N<1000000;N++){
    sort(ans.begin(),ans.end());
    if(N>=ans.size()-1)
        out<<-1<<endl;
    else out<<ans[N+1]<<endl;
    }
}