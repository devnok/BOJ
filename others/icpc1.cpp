#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

const int K = 16769023;
int main(){
    int k=1,n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            putchar(abs(n-j-1)<=i?42:32);
        }
        puts("");
    }
}