#include<iostream>
#include<vector>
#include<numeric>
#include<functional>
using namespace std;

int n,a[100010],psum[100010];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    partial_sum(a,a+n,psum,bit_xor<int>());
    
}